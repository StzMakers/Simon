/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////PLAYER
void Player(){
  if (gameMode == 2){         //Si se ha elegido modo de juego 2
    playerMode2();              //Ejecuta esta función
  } else {                    //En caso contrario
    playerMode1();              //Ejecuta esta otra, es la misma para el modo de juego 1 y 3, en el modo de juego 3 lo que cambia es la parte de la CPU
  } 
}


void playerMode1(){           //MODO DE JUEGO 1 y 3
  myTurn=true;                          //Empieza el turno del jugador  
  int playerRound=0;                    //Ronda 0 , para empezar a mirar en la primera posición del array
  
  while (myTurn==true){                 //Mientras sea su turno...                 
    myButton=checkButtons();                //Comprueba la pulsación del botón
    if (myButton!=0){                       //Si se ha pulsado algún botón      
      if (myButton==game[playerRound]){       //Si ese botón es igual a lo grabado en game[playerRond]        
        while (myButton==checkButtons()){       //Mientras se siga pulsando el botón....            
          turnLedOn(game[playerRound], 0);      //Enciende ese led durante 0 ms , al estar el botón pulsado todo el rato no se apaga
        }            
        playerRound++;                          //Siguiente elemento del array
        
        if (playerRound>level){                 //Si la jugada llega al número del nivel (cada nivel añade una jugada nueva)
          level++;                                  //Sube de nivel
          lcd_texts(true);                          //Texto en pantalla    
          if ((level%3 == 0) and (ledPause>minPause)){    //Si el número de nivel es múltiplo de 3 y todavía no se ha alcanzado la velocidad máxima
            ledPause-=50;                                   //Resta 50ms al tiempo que los leds están encendidos (velocidad del juego)
          }
          if (level>maxLevel){                      //Si hemos llegado al nivel máximo...          
            youWin();                                   //YOU WIN
          }
          myTurn=false;                             //Acaba el turno del jugador        
          ledsRotateOnOff(50);                      //Secuencia de luces
        }       
      } else {                              //si no...                      
        youLose();                              //Pierdes
      }                            
    }       
  }
  delay(500);                             //Pausa de 0.5seg hasta que pasa el turno a la CPU
}

void playerMode2(){                     //MODO DE JUEGO 2
  myTurn=true;                          //Empieza el turno del jugador
  int playerRound = level;                  //En la jugada level
  while (myTurn==true){                 //Mientras sea su turno...    
    myButton=checkButtons();                      //Comprueba la pulsación del botón
    if (myButton!=0){                   //Si se ha pulsado algún botón
      if (myButton==game[playerRound]){     //Si ese botón es igual a lo grabado en game[playerRond]
        while (myButton==checkButtons()){     //Mientras se esté pulsando el botón
          turnLedOn(game[playerRound], 0);      //Enciende ese led 
        }
        playerRound--;                                  //Siguiente jugada
        if (playerRound<0){                             //Si la jugada llega al número del nivel (cada nivel añade una jugada nueva)
          level++;                                          //Sube de nivel
          lcd_texts(true);                          //Texto en pantalla    
          if ((level%3 == 0) and (ledPause>minPause)){      //Si el número de nivel es múltiplo de 3 y todavía no se ha alcanzado la velocidad máxima
            ledPause-=50;                                   //Resta 50ms al tiempo que los leds están encendidos (velocidad del juego)
          }
          if (level>maxLevel){                      //Si hemos llegado al nivel máximo...          
            youWin();                                   //YOU WIN
          }
          myTurn=false;                             //Acaba el turno del jugador        
          //ledsRotateOnOff(50);                      //Secuencia de luces
        }       
      } else {                              //si no...                      
        youLose();                              //Pierdes
      }                            
    }   
    delay(50);                     //Pausa de 50ms (para probar el comportamiento de los botones, seguramente se pueda quitar)
  }
  delay(500);                      //Pausa de 0.5seg hasta que pasa el turno a la CPU
}

/**********************************************************************************************/

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
