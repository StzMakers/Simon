/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////CPU
void CPU(){  
  game[level] = leds[random(0,3)];    //Añade al array game en posición level, un número al azar entre 0 y 3
  if (gameMode != 3){                 //Si no estamos en el modo de juego 3...
    for (int i=0;i<=level;i++){         //Empieza a recorrer el array desde la posición 0, hasta la posición level
      turnLedOn(game[i], ledPause);        //Enciende el led game[i] durante 500ms         
    }        
  } else {                                //En modo de juego 3
    turnLedOn(game[level], ledPause);     //Solo enciende el led que corresponde a la última posición             
  }       
}
/**********************************************************************************************/
