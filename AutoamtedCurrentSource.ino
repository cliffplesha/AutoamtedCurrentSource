/*
   Still need to get multiplexing working
   add control statements to cause correct DigitalPot to change (when multiplexing working)
   change Ch1 and Ch3 resistor from 25K to 250K
   get ethernet working
   get matlab -> ethernet working

*/

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetClient.h>

// Pin control for communication with fiber optics
const int csMaster = 9; //only CS pin used. Connects to multiplexer chip
const int transferPin = 8; //secondary input to AND-Gates for SPI (CLK/MOSI) communication
const int ethernetPin = 10;
const int CLK_2 = 7; // pin used to control MOSI to non-MCP23S08 chips

//Bytes used to control AD5235 digital poteomter
const byte P1 = B00000000;
const byte P2 = B00000001;
const byte w = B10110000;
const byte r = B10100000;

long int ltw=0;

//Ethernet Address for Wiznet Chip
byte mac[] = {0x99, 0xA8, 0xFA, 0x6E, 0x38, 0x4A}; //Must change per EtherTen
byte subnet[] = {255, 255, 255, 0};
byte gateway[] = {9, 8, 5, 4, 3, 2};

//Static IP Address for Wiznet Chip
IPAddress ip(169, 254, 94, 71); //Windows IP address
//IPAddress ip(10, 95, 101, 70); //mac IP address

//Port tot listen on
EthernetServer server(1234);

//defined bytes used to send data to Digital Pot
byte combyte = B00000000;
byte databyte1 = B00000000;
byte databyte2 = B00000000;

byte b0;
String cmd;

EthernetClient client;


//SPISettings SPIMCP23S08(1000000, MSBFIRST, SPI_MODE0);
//SPISettings SPIAD5235(1000000, MSBFIRST, SPI_MODE0);

void setup() {

  delay( 50 );   // allow some time (50 ms) after powerup and sketch start, for the Wiznet W5100 Reset IC to release and come out of reset.

  Ethernet.begin(mac, ip, subnet, gateway);
  server.begin();
//  Serial.begin(9600);
  
//   initalize SPI:
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV32);

  // SPI.beginTransaction(SPIMCP23S08);

  // Define communication pin outputs:
  pinMode(csMaster, OUTPUT);
  pinMode(transferPin, OUTPUT);
  pinMode(ethernetPin, OUTPUT);
  pinMode(7, OUTPUT);
  
//  digitalWrite(csMaster, HIGH);
//  digitalWrite(transferPin, LOW);
//  digitalWrite(ethernetPin, HIGH);
//  digitalWrite(CLK_2, LOW);

  MCP23S08sendCommand(0x00, 0x00);
  delay(500);
  MCP23S08sendCommand(0x09, 0xff);

//   test relay code area
//  pinMode(13, OUTPUT);
//  pinMode(11, OUTPUT);
//  delay(10);
//  digitalWrite(13, LOW);
//  digitalWrite(11, LOW);
//  digitalWrite(9, LOW);
//  digitalWrite(8, LOW);
//  digitalWrite(7, LOW);

//  client = server.available();
}

void loop() {
  cmd = ""; //clear command
  combyte = B00000000; //clear data and bytes sent to DigitalPot
  databyte1 = B00000000;
  databyte2 = B00000000;
  
//  *************** SERVER CODE ***************

//  SPI.setDataMode(SPI_MODE0);
  EthernetClient client = server.available();
  if (client) {
    while (client.available()) {
      char comchar = client.read();
      cmd += comchar;
    }
    int eos = cmd.indexOf("\n"); //telnet uses both \n and \r for end of line
    if (eos != -1) {
      cmd = cmd.substring(0, eos);

      int cr = cmd.indexOf('\r');
      if (cr != -1) cmd = cmd.substring(0, cr);
    }
    cmd.toLowerCase();
//    String cmd2 = cmd;
//    cmd2 += "\n";
//    char serverbuf[100];
//    cmd.toCharArray(serverbuf,100);
//    server.print(serverbuf);
//    server.println(cmd.length());
//    server.println(cmd.toInt());
    chunkCommand(cmd);
  }

// ************  SERIAL CODE ****************
//    while (!Serial.available()) {
//      
//    }
//    while (Serial.available()) {
//      // read incoming serial string and store in varialbe cmd
//      cmd += char(Serial.read());
//      delay(2);
//    }
//    Serial.println(cmd); //Test to see if recieved string properly
//    cmd.toLowerCase();
//    chunkCommand(cmd);
}
