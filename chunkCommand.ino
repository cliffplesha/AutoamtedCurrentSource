/* 
 *Take command, intprete command, send command structure to correct function
 */
void chunkCommand(String pot) {
//  activateDigitalPot(pot.toInt());
  
  //code used for testRelay function. Format input "<pin#>:<HIGH/LOW>"
//  int place1 = pot.indexOf(":");
//  String token1 = pot.substring(0,place1);
//  String token2 = pot.substring(place1+1);
//  testRelay(token1.toInt(), token2);

  // code used for main control off the current source
  int place1 = pot.indexOf(":");
  int place2 = pot.indexOf(":",place1+1);
  String token1 = pot.substring(0,place1);
  String token2 = pot.substring(place1+1,place2);
  String token3 = pot.substring(place2+1);


//  server.print("token1 is: ");
//  server.println(token1);
//  server.print("token2 is: ");
//  server.println(token2);
//  server.print("token3 is: ");
//  server.println(token3);

//  Serial.print("token1 is: ");
//  Serial.println(token1);
//  Serial.print("token2 is: ");
//  Serial.println(token2);
//  Serial.print("token3 is: ");
//  Serial.println(token3);

  setupDataByte(token1, token2, token3);

}

