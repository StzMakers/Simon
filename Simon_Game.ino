/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
void selectGameMode(){                  //Elegir modo de juego
  myButton=checkButtons();              //Almacena en myButton el botón pulsado
  switch (myButton){                    
    case 7:                             //Si se ha pulsado el botón GREEN, modo de juego 1      
      gameMode = 1;
      turnLedOn(7, ledPause); 
      break;
    case 4:      
      gameMode = 2;                     //Si se ha pulsado el botón RED, modo de juego 2
      turnLedOn(4, ledPause); 
      break;
    case 6:      
      gameMode = 3;                     //Si se ha pulsado el botón YELLOW, modo de juego 3
      turnLedOn(6, ledPause); 
      break;
  }  
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////END GAME

void youLose(){           //HAS PERDIDO  
  myTurn=false;           //Mi turno es falso
  endGame = true;         //Fin de juego es verdadero
  ledsGameOver();         //Secuencia de luces
  asm volatile (" jmp 0");  //SoftReset
}

void youWin(){            //HAS GANADO
  myTurn=false;           //Mi turno es falso
  endGame = true;         //Fin de juego es verdadero
  ledsWin();              //Secuencia de luces
}
