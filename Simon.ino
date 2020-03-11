/*
  JUEGO SIMON  v4.0
  STZMAKERS
*/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//1.- Definir variables

//Pulsadores y leds
int BotonGREEN = 8;          //BOTON VERDE
int BotonYELLOW = 9;         //BOTON AMARILLO
int BotonRED = 10;           //BOTON ROJO
int BotonBLUE = 11;          //BOTON AZUL

int ledRED = 4;              //LED ROJO
int ledBLUE = 5;             //LED AZUL
int ledYELLOW = 6;           //LED AMARILLO
int ledGREEN = 7;            //LED VERDE

#define buzzer 3             //BUZZER

//Array con los pines de los leds
int leds[4]={7,6,4,5};

//Otras variables
#define maxLevel 20     //Constante, no se pone ";"
int game[maxLevel] = {};  //Array para guardar las jugadas correctas

int level = 0;          //Nivel actual del juego
bool myTurn=true;       //Para comprobar cuando finaliza el turno
int myButton=0;         //Donde se guarda la pulsación del jugador
bool endGame=false;     //Fin de juego
byte gameMode = 0;      //Mode 1 -> Normal  //  Mode 2 -> Inverso  //  Mode 3 -> A ciegas
int playerRound = 0;                  //En la jugada 0    
int ledPause = 400;
int minPause = 100;

#define numTextOk 3
String textosOk[numTextOk] = {
                                "MUY BIEN",
                                "SI!!!!",
                                "OOH YEAH!!"                                                           
};

#define numTextNoOk 3
String textosNoOk[numTextNoOk] = {
                                "OUCH",
                                "VAYA...",
                                "JA JA JA"                                                           
};

float notes[4] = {
                440,
                880,
                587.33,
                784                
};

//2.SETUP 
void setup() {
  Serial.begin(9660);
  // Pines de ENTRADA
  pinMode (BotonGREEN, INPUT);
  pinMode (BotonYELLOW, INPUT);
  pinMode (BotonRED, INPUT);
  pinMode (BotonBLUE, INPUT);
  
  // Pines de SALIDA
  pinMode (ledGREEN, OUTPUT);
  pinMode (ledYELLOW, OUTPUT);
  pinMode (ledRED, OUTPUT);
  pinMode (ledBLUE, OUTPUT);
  pinMode (buzzer, OUTPUT);
  
  //Semilla RANDOM
  randomSeed(analogRead(A0));
  
  //Inicio Pantalla
  lcd_init();
  
  lcd_gameMode_selection();
  
}

void loop() {  
  if (endGame==false){  //Si el juego no acaba
    CPU();              //Turno del CPU
    Player();           //Turno del Player
  }    
}
