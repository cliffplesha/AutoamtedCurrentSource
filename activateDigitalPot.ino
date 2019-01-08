/*
   Function used to control MCP23S08 to acitivate 4 AD5865 Digital Pots
*/
void activateDigitalPot(int potCS) {
  /*Serial.println("ping 1");
    digitalWrite(transferPin, LOW);
    digitalWrite(csMaster, LOW);
    delay(10);
    Serial.println("ping 2");
    if (potCS == 1) {
    //SPI.transfer(0x01);
    Serial.println("turn pot 1 on");
    }
    else if (potCS == 0) {
    //SPI.transfer(0x00);
    Serial.println("turn all pots off");
    }
    else{
    Serial.println("not valid channel value (1-4)");
    }*/
  switch (potCS) {
    case 0:
//    Serial.println("set all to LOW");
      MCP23S08sendCommand(0x09, 0x00);
      break;
    case 1:
//    server.println("set 1 to LOW");
//      Serial.println("set 1 to LOW");
      MCP23S08sendCommand(0x09, 0xfe);
      break;
    case 2:
//      Serial.println("set 2 to LOW");
      MCP23S08sendCommand(0x09, 0xfd);
      break;
    case 3:
//      Serial.println("set 3 to LOW");
      MCP23S08sendCommand(0x09, 0xfb);
      break;
    case 4:
//      Serial.println("set 4 to LOW");
      MCP23S08sendCommand(0x09, 0xf7);
      break;
    case 5:
//      Serial.println("set 5 to LOW");
      MCP23S08sendCommand(0x09, 0xef);
      break;
    case 6:
//      Serial.println("set 6 to LOW");
      MCP23S08sendCommand(0x09, 0xdf);
      break;
    case 7:
//      Serial.println("set 7 to LOW");
      MCP23S08sendCommand(0x09, 0xbf);
      break;
    case 8:
//      Serial.println("set 8 to LOW");
      MCP23S08sendCommand(0x09, 0x7f);
      break;
    case 10:
//      Serial.println("set all to HIGH");
      MCP23S08sendCommand(0x09, 0xff);
      break;
    default:
//      Serial.println("Not Valid cammand for MCP23S08");
//      Serial.println("Error in activateDigitalPot function");
      MCP23S08sendCommand(0x09, 0xff);
      break;
  }
//  delay(10);
  /* digitalWrite(csMaster, HIGH);
    digitalWrite(transferPin, HIGH);
    Serial.println("ping 3"); */
}

