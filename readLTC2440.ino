float readLTC2440(int CS) {
  /*
     first pulse CS (HIGH -> LOW): to cause it to integrate at new value
     Pull CS LOW: Causes output of data on SPI command
     read incomming data 32bits (MSB First)
     parse Data:
    31 = EOS
    30 = Dummy always 0
    29 = Conversion HIGH = Vin > 0 / LOW = Vin < 0
    28 - 5 = Conversion with MSBFIRST
    4 - 0 = Sub LSB and can be thrown away without issue
  */
  byte b0;
  byte b1;
  byte b2;
  byte b3;
  byte sig;
  activateDigitalPot(8); //create if statement such that 1 -> 8, 2 -> 7, 3 -> 6, 4 -> 5
  delay(100);
  activateDigitalPot(10);
  delay(5000);
  activateDigitalPot(8);
  boolean transfered = false;

  while (transfered == false) {
//    if (digitalRead(MISO != LOW)) {
//      delay(10);
//    }
//    else if (digitalRead(MISO) == LOW) {
      ltw = 0;
      sig = 0;
      transfered = true;

      b0 = SPI.transfer(0x00);
      b1 = SPI.transfer(0x00);
      b2 = SPI.transfer(0x00);
      b3 = SPI.transfer(0x00);
      Serial.print("B0 is: ");
      Serial.println(b0, BIN);
      Serial.print("B1 is: ");
      Serial.println(b1, BIN);
      Serial.print("B2 is: ");
      Serial.println(b2, BIN);
      Serial.print("B3 is: ");
      Serial.println(b3, BIN);
//    }
  }
  activateDigitalPot(10);
  if (bitRead(b0,5) == 0); sig = 1;
  if (bitRead(b0,7) == 1){ 
//    Serial.println("error in ADC2440");
//    return;
  }
  if (bitRead(b0,6) & bitRead(b0,5) ==  1) Serial.println("Voltage input out of range");
  b0 &= 0x1F;
  ltw |= b0;
  ltw <<= 8;
  ltw |= b1;
  ltw <<= 8;
  ltw |= b2;
  ltw <<= 8;
  ltw |= b3;
  Serial.print("ltw before shifting is: ");
  Serial.println(ltw,BIN);

  ltw >>= 5;
//  Serial.print("ltw after shifting is: ");
//  Serial.println(ltw,BIN);
  float output = ((ltw * 4.999) / 16777216);
  if(sig == 1) output *= -1;
  return output;
  Serial.print("voltage read by ADC2440 is ");
}


