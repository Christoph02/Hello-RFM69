#include <RFM69.h>    //get it here: https://www.github.com/lowpowerlab/rfm69
#include <SPI.h>
 
#define NETWORKID     100  // The same on all nodes that talk to each other
#define NODEID        2    // The unique identifier of this node
#define GATEWAYID     1    // same as RECEIVER
 
//Match frequency to the hardware version of the radio on your Feather
#define FREQUENCY     RF69_433MHZ
//#define FREQUENCY     RF69_868MHZ
//#define FREQUENCY     RF69_915MHZ
#define ENCRYPTKEY    "7-R|6tITi;JQjw_m" //exactly the same 16 characters/bytes on all nodes!
#define IS_RFM69HCW   false // set to 'true' if you are using an RFM69HCW module
 
//*********************************************************************************************
#define SERIAL_BAUD   115200
 
#define RFM69_CS      10
#define RFM69_IRQ     2
#define RFM69_IRQN    0  // Pin 2 is IRQ 0!
#define RFM69_RST     9
 
#define LED           13   // onboard blinky

int TRANSMITPERIOD = 5000; //transmit a packet to gateway so often (in ms)
long lastPeriod = -1; //
 
uint16_t packetnum = 0;  // packet counter, we increment per xmission

float th02Trnd=0; //TH02 temperature rounded
float th02Hrnd=0; //TH02 humidity rounded
 
RFM69 radio = RFM69(RFM69_CS, RFM69_IRQ, IS_RFM69HCW, RFM69_IRQN);

typedef struct {
  int           nodeId; //store this nodeId
  uint16_t      num;    //Packetnumber
  unsigned long uptime; //uptime in ms
  float         temp;   //temperature in °C
  float         hum;    //humidity in %
} Payload;
Payload theData;

void setup() {
  TH02setup();
//  while (!Serial); // wait until serial console is open, remove if not tethered to computer
  Serial.begin(SERIAL_BAUD);
 
  Serial.println("Arduino RFM69W Transmitter");
  
  // Hard Reset the RFM module
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);
  delay(100);
  digitalWrite(RFM69_RST, LOW);
  delay(100);
 
  // Initialize radio
  radio.initialize(FREQUENCY,NODEID,NETWORKID);
  if (IS_RFM69HCW) {
    radio.setHighPower();    // Only for RFM69HCW & HW!
  }
  radio.setPowerLevel(31); // power output ranges from 0 (5dBm) to 31 (20dBm)
  
  radio.encrypt(ENCRYPTKEY);
  
  pinMode(LED, OUTPUT);

  
  Serial.print("\nTransmitting at ");
  Serial.print(FREQUENCY==RF69_433MHZ ? 433 : FREQUENCY==RF69_868MHZ ? 868 : 915);
  Serial.println(" MHz");
}
 
 
void loop() {

  //check for any received packets
  if (radio.receiveDone())
  {
    Serial.print('[');Serial.print(radio.SENDERID, DEC);Serial.print("] ");
    for (byte i = 0; i < radio.DATALEN; i++)
      Serial.print((char)radio.DATA[i]);
    Serial.print("   [RX_RSSI:");Serial.print(radio.readRSSI());Serial.print("]");

    if (radio.ACKRequested())
    {
      radio.sendACK();
      Serial.print(" - ACK sent");
      delay(10);
    }
    Blink(LED,5,3);
    Serial.println();
  }
  
  //transmit packet
  //wait TRANSMITPERIOD between transmits
  int currPeriod = millis()/TRANSMITPERIOD;
  if (currPeriod != lastPeriod)
  {
    TH02run(); //get sensordata from TH02
    //fill in the struct with new values
    theData.nodeId = NODEID;
    theData.num=packetnum++;
    theData.uptime = millis();
    theData.temp = th02Trnd;
    theData.hum = th02Hrnd;

    if (radio.sendWithRetry(GATEWAYID, (const void*)(&theData), sizeof(theData)))
      Serial.print(" package OK: "); Serial.println(theData.num);
    Blink(LED, 50, 3); //blink LED 3 times, 50ms between blinks
    lastPeriod=currPeriod;
    
//  char radiopacket[20] = "Hello World #";
//  itoa(packetnum++, radiopacket+13, 10);
//  Serial.print("Sending "); Serial.println(radiopacket);
    
//  if (radio.sendWithRetry(RECEIVER, radiopacket, strlen(radiopacket))) { //target node Id, message as string or byte array, message length
//    Serial.println("OK");
//    Blink(LED, 50, 3); //blink LED 3 times, 50ms between blinks
//  }
 
  radio.receiveDone(); //put radio in RX mode
  Serial.flush(); //make sure all serial data is clocked out before sleeping the MCU
  }
}
 
void Blink(byte PIN, byte DELAY_MS, byte loops)
{
  for (byte i=0; i<loops; i++)
  {
    digitalWrite(PIN,HIGH);
    delay(DELAY_MS);
    digitalWrite(PIN,LOW);
    delay(DELAY_MS);
  }
}
