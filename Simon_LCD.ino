void lcd_init(){
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(2.5); // Draw 2X-scale text   
  display.setTextColor(WHITE);
  display.setCursor(1, 0);
  display.println("Simon Says");  
  display.display();      // Show text
  display.setTextSize(1); // Draw 1X-scale text
  display.setCursor(30, 24);
  display.println("   by StzMakers");  
  display.display();      // Show text
  //Secuencia leds inicio
  ledsInit();
  delay(1000);
  display.clearDisplay();  
}


void lcd_gameMode_selection(){    
    display.setTextSize(2); // Draw 3X-scale text
    display.setTextColor(WHITE);
    display.setCursor(1, 15);  
    display.print("  Select  ");
    display.display();      // Show text
    delay(500);
    display.clearDisplay();  
    display.setCursor(3, 15);  
    display.print("Game Mode");
    display.display();      // Show text
    delay(700);
    display.clearDisplay(); 

    display.setTextSize(0.5);
    display.setCursor(1, 2);  
    display.println("GREEN: Normal Mode");            
    display.setCursor(1, 13);  
    display.print("RED: Inverse Mode");   
    display.setCursor(1, 24);      ;  
    display.print("YELLOW: Only 1");
    display.display();      // Show text           
    //Elegir modo de juego
  while (gameMode == 0){
    selectGameMode();    
  }   
  ledsBlink(1, 300);   //Enciende y apaga todos los leds 1 vez, con un delay 300 
    display.clearDisplay();
    display.setTextSize(2); // Draw 3X-scale text
    display.setTextColor(WHITE);
    display.setCursor(1, 15);  
    display.print("GO!!!");
    display.display();      // Show text
    delay(500);
    display.clearDisplay(); 
    display.display();      // Show text
    display.setCursor(1, 15);  
    display.print("Level: ");
    display.print(level+1);
    display.display();      // Show text
}

void lcd_texts(bool ok){
    display.clearDisplay();
    display.setTextSize(2); // Draw 3X-scale text
    display.setTextColor(WHITE);
    display.setCursor(1, 15);  
    display.print("Level: ");
    display.print(level+1);
    display.display();      // Show text
    if (ok == true){      
      if (random(0,15)<2){
        display.clearDisplay();
        display.setTextSize(2); // Draw 3X-scale text
        display.setTextColor(WHITE);
        display.setCursor(1, 15);  
        display.print(textosOk[random(0, level)]); 
        display.display();      // Show text      
      }
             
    } else {
      display.clearDisplay();
      display.setTextSize(2); // Draw 3X-scale text
      display.setTextColor(WHITE);
      display.setCursor(1, 15);  
      display.print(textosNoOk[random(0, numTextNoOk-1)]);  
      display.display();      // Show text  
      delay(2000);
    }
    
}
