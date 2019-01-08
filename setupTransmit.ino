/*Transmit function
   First string is  what channel: 1-4 (two I_bias, two flux_bias)
   Second string is what wiper position: course or fine
   Third string is the value for the wiper position to go to (0-1023)
*/
void setupTransmit(String outputChannel) {
  activateDigitalPot(outputChannel.toInt());
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  digitalWrite(ethernetPin,HIGH);
  digitalWrite(transferPin, HIGH);
  digitalWrite(CLK_2,HIGH); 
//  Serial.println("transfering to AD5235");
  delay(100);
  SPI.transfer(combyte);
  SPI.transfer(databyte1);
  SPI.transfer(databyte2);
  digitalWrite(CLK_2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(ethernetPin,LOW);
  delay(100);
  
  activateDigitalPot(10);
//  digitalWrite(csMaster, LOW);
//  delay(10);
//  SPI.transfer(0x40);
//  SPI.transfer(0x09);
//  SPI.transfer(0xff);
//  digitalWrite(csMaster,HIGH);
//  digitalWrite(transferPin, LOW);
}
