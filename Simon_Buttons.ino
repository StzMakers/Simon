/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/////////////////BOTONES****
byte checkButtons(){  
  //myButton=0;                           //Inicializamos la variable   
  if (digitalRead(BotonGREEN)==HIGH){      //Si se ha pulsado el botón GREEN
    tone (buzzer, notes[0], 50);
    return 7;                         //Almacenamos en la variable el número 7, que corresponde al led GREEN    
  }else 
  if (digitalRead(BotonRED)==HIGH){    //Si se ha pulsado el botón RED
    tone (buzzer, notes[1], 50);
    return 4;                         //Almacenamos en la variable el número 4, que corresponde al led RED    
  }else
  if (digitalRead(BotonBLUE)==HIGH){    //Si se ha pulsado el botón BLUE
    tone (buzzer, notes[2], 50);
    return 5;                         //Almacenamos en la variable el número 5, que corresponde al led BLUE    
  }else
  if (digitalRead(BotonYELLOW)==HIGH){   //Si se ha pulsado el botón YELLOW
     tone (buzzer, notes[3], 50);
    return 6;                         //Almacenamos en la variable el número 6, que corresponde al led YELLOW    
  } else 
    return 0;
}
/**********************************************************************************************/

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
