void setupDataByte(String token1, String token2, String token3) {
  int data = token3.toInt();

  if (token2 == "readpot") {
    combyte = combyte + r;
    if (token3 == "cour") {
      combyte = combyte + P1;
    }
    else if (token3 == "fine") {
      combyte = combyte + P2;
    }
    else{};
    readPot(token1.toInt());
  }
  
  else if (data >= 0 && data <= 1023) {
    databyte1 = data / 256;
    databyte2 = data - 256 * (data / 256);
  }
  else {
    //    Serial.println("third token invalid: please specify an RDAC position between 0 and 1023 or R(EAD)");
    return;
  }
  if (token2 == "cour") {
    //    Serial.println("Changing course position");
    combyte = combyte + P1 + w;
    setupTransmit(token1);
  }
  else if (token2 == "fine") {
    //    Serial.println("Changing fine position");
    combyte = combyte + P2 + w;
    setupTransmit(token1);
  }
  else if (token2 == "readadc") {
//    Serial.println("in readADC mode");
//    Serial.println(readLTC2440(token1.toInt()));
  }
  else if (token1 == "initialize")
  {
    MCP23S08sendCommand(0x00, 0x00);
    delay(1000);
    MCP23S08sendCommand(0x09, 0xff);
    //    Serial.println("MCP initialized");
  }
  else {
    //    Serial.println("Unknown Command");
  }
}


