/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////LUCES
void turnLedOn(int ledN, int pause){        //Enciende y apaga el led "ledN" con una pausa de "pause"ms
  digitalWrite(ledN, HIGH);
  if (ledN == 7) {
    tone (buzzer, notes[0], 50);
  } else if (ledN == 4) {
    tone (buzzer, notes[1], 50);
  } else if (ledN == 5) {
    tone (buzzer, notes[2], 50);
  } else tone (buzzer, notes[3], 50);
  delay(pause);
  digitalWrite(ledN, LOW);
  delay(pause);
}
/**********************************************************************************************/
void ledsBlink(int times, int pause){       //Enciende y apaga todos los leds "times" veces con una pausa de "pause"
  for (int n=0;n<times;n++){
    for (int i=0;i<4;i++){
      digitalWrite(leds[i], HIGH);   
    }
    delay(200);
    for (int i=0;i<4;i++){
      digitalWrite(leds[i], LOW);   
    }
    delay(pause);  
  }  
}
/**********************************************************************************************/
void ledsRotateOnOff(int pause){            //Enciende y apaga todos los leds, en secuencia con una pausa "pause"ms
  for (int i=0;i<4;i++){
    digitalWrite(leds[i], HIGH);
    delay(pause);
    digitalWrite(leds[i], LOW);
  }  
  delay(200);
}
/**********************************************************************************************/
void ledsRotate(int state, int pause){      //Enciende o apaga "state" todos los leds en secuencia con una pausa "pause"ms
  for (int i=0;i<4;i++){
    digitalWrite(leds[i], state);
    delay(pause);    
  }
}
/**********************************************************************************************/
void ledsGameOver(){
  ledsBlink(3, 50);
  turnLedOn(7, 100);
  turnLedOn(5, 100);
  turnLedOn(6, 100);
  turnLedOn(4, 100);  
  lcd_texts(false);
}
/**********************************************************************************************/
void ledsWin(){
 ledsRotateOnOff(100);
 ledsRotateOnOff(100);
 ledsRotateOnOff(100); 
 ledsRotate(1, 100);
 ledsRotate(0, 500);
}
/**********************************************************************************************/
void ledsInit(){
  ledsRotateOnOff(100); //Enciende y apaga secuencialmente los leds
  ledsRotate(1, 200);  //Pone todos los leds en 1, con un delay 200
  ledsRotate(0, 200);  //Pone todos los leds en 0, con un delay 200
  ledsBlink(1, 300);   //Enciende y apaga todos los leds 1 vez, con un delay 300 
}
/**********************************************************************************************/

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
