void readPot(int potCS) {
  // function used to read information from AD5235 Digital Potentiometer

  byte b0;
  byte b1;
  byte b2;
  activateDigitalPot(potCS);
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  digitalWrite(ethernetPin,HIGH);
  digitalWrite(transferPin, HIGH);
  digitalWrite(CLK_2,HIGH); 
//  Serial.println("transfering to AD5235");
  delay(100);
  b0 = SPI.transfer(0xA0);
  b1 = SPI.transfer(0xff);
  b2 = SPI.transfer(0xff);
  digitalWrite(CLK_2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(ethernetPin,LOW);
  delay(100);

  Serial.println("First bit of info ");
  Serial.println(b0, BIN);
  Serial.println(b1, BIN);
  Serial.println(b2, BIN);

  activateDigitalPot(potCS);
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  digitalWrite(ethernetPin,HIGH);
  digitalWrite(transferPin, HIGH);
  digitalWrite(CLK_2,HIGH); 
//  Serial.println("transfering to AD5235");
  delay(100);
  b0 = SPI.transfer(0xff);
  b1 = SPI.transfer(0xff);
  b2 = SPI.transfer(0xff);
  digitalWrite(CLK_2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(ethernetPin,LOW);
  delay(100);

  Serial.println("Second bit of info");
  Serial.println(b0, BIN);
  Serial.println(b1, BIN);
  Serial.println(b2, BIN);
  
}

