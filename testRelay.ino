/*
   Test script to test if fiber optic relays are working:
   to use this script in Main comment out SPI lines and
   in setup function add:
   pinMode(13,OUTPUT);
   pinMode(11,OUTPUT);
   digitalWrite(transferPin,HIGH);
   CLK = 13
   MOSI = 11
   CSMASTER = 8
*/
void testRelay(int fiberPin, String output) {
  delay(10);
  Serial.print(fiberPin);
  Serial.print(" is ");
  Serial.println(output);
  digitalWrite(ethernetPin, LOW);
  delay(100);
  if (output == "high") {
    digitalWrite(fiberPin, HIGH);
  }
  else if (output == "low") {
    digitalWrite(fiberPin, LOW);
  }
  else {
//    Serial.println("String output in testRelay is not working.");
//    server.println("Format is: <pin#>:<high/low>");
  }
//  digitalWrite(ethernetPin, HIGH);
  delay(10);
}

