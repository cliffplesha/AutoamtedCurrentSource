void MCP23S08sendCommand(int address, int data) {
//  SPI.beginTransaction(SPIAD5235);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  digitalWrite(ethernetPin,HIGH);
  digitalWrite(transferPin, HIGH);;
  digitalWrite(csMaster, LOW);
  
  delay(1000);
  //  send in the address and value via SPI:
//  delay(100);

  // SPI addressing 0x40 with A0 and A1 set to ground and R/W bit set to output
  SPI.transfer(0x40);
//  Serial.print("Sending address: ");
//  Serial.println(address, BIN);
  SPI.transfer(address);
//  Serial.print("Sending data: ");
//  Serial.println(data, BIN);
  SPI.transfer(data);
  

//  delay(10);
  // take the chipSelect pin high to de-select the chip:
  digitalWrite(csMaster, HIGH);
  digitalWrite(transferPin, LOW);

  digitalWrite(ethernetPin,LOW);

//  SPI.endTransaction();
}
