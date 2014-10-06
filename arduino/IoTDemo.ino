#include <rgb_matrix.h>
#include <SPI.h>
#include <SoftwareSerial.h>

//Puertos de comunicacion serial con electric imp
const int IMP_SERIAL_RX = 8;
const int IMP_SERIAL_TX = 9;

#define N_X 1
#define N_Y 1

//Hardware SPI Matriz de 8x8
#define DATA_PIN  11
#define CLK_PIN   13
#define LATCH_PIN 7

//Inicializacion de variables
rgb_matrix M = rgb_matrix(N_X, N_Y, DATA_PIN, CLK_PIN, LATCH_PIN);
String cmd="";
int myChar ; 

// Software Serial
SoftwareSerial impSerial(IMP_SERIAL_RX, IMP_SERIAL_TX);

void setup()
{
  //Inicializaciones seriales
  Serial.begin(4800);
  impSerial.begin(4800);
}

void hook()
{
  if (myChar != -1){
    String command = cmd.substring(cmd.length()-1);
    if (myChar == 'H'){
      M.clear();
      M.plot(0,0,3,TOP_LAYER);
      M.plot(1,0,3,TOP_LAYER);
      M.plot(2,0,3,TOP_LAYER);
      M.plot(3,0,3,TOP_LAYER);
      M.plot(4,0,3,TOP_LAYER);
      M.plot(5,0,3,TOP_LAYER);
      M.plot(6,0,3,TOP_LAYER);
      M.plot(7,0,3,TOP_LAYER);
      M.plot(0,1,3,TOP_LAYER);
      M.plot(7,1,3,TOP_LAYER);
      M.plot(0,2,3,TOP_LAYER);
      M.plot(2,2,3,TOP_LAYER);
      M.plot(5,2,3,TOP_LAYER);
      M.plot(7,2,3,TOP_LAYER);
      M.plot(0,3,3,TOP_LAYER);
      M.plot(7,3,3,TOP_LAYER);
      M.plot(0,4,3,TOP_LAYER);
      M.plot(2,4,3,TOP_LAYER);
      M.plot(3,4,3,TOP_LAYER);
      M.plot(4,4,3,TOP_LAYER);
      M.plot(5,4,3,TOP_LAYER);
      M.plot(7,4,3,TOP_LAYER);
      M.plot(0,5,3,TOP_LAYER);
      M.plot(3,5,3,TOP_LAYER);
      M.plot(4,5,3,TOP_LAYER);
      M.plot(7,5,3,TOP_LAYER);
      M.plot(0,6,3,TOP_LAYER);
      M.plot(7,6,3,TOP_LAYER);
      M.plot(0,7,3,TOP_LAYER);
      M.plot(1,7,3,TOP_LAYER);
      M.plot(2,7,3,TOP_LAYER);
      M.plot(3,7,3,TOP_LAYER);
      M.plot(4,7,3,TOP_LAYER);
      M.plot(5,7,3,TOP_LAYER);
      M.plot(6,7,3,TOP_LAYER);
      M.plot(7,7,3,TOP_LAYER);
    }
    if (myChar == 'S'){
      M.clear();
      M.plot(0,0,4,TOP_LAYER);
      M.plot(1,0,4,TOP_LAYER);
      M.plot(2,0,4,TOP_LAYER);
      M.plot(3,0,4,TOP_LAYER);
      M.plot(4,0,4,TOP_LAYER);
      M.plot(5,0,4,TOP_LAYER);
      M.plot(6,0,4,TOP_LAYER);
      M.plot(7,0,4,TOP_LAYER);
      M.plot(0,1,4,TOP_LAYER);
      M.plot(7,1,4,TOP_LAYER);
      M.plot(0,2,4,TOP_LAYER);
      M.plot(2,2,4,TOP_LAYER);
      M.plot(5,2,4,TOP_LAYER);
      M.plot(7,2,4,TOP_LAYER);
      M.plot(0,3,4,TOP_LAYER);
      M.plot(7,3,4,TOP_LAYER);
      M.plot(0,5,4,TOP_LAYER);
      M.plot(2,5,4,TOP_LAYER);
      M.plot(3,5,4,TOP_LAYER);
      M.plot(4,5,4,TOP_LAYER);
      M.plot(5,5,4,TOP_LAYER);
      M.plot(7,5,4,TOP_LAYER);
      M.plot(0,4,4,TOP_LAYER);
      M.plot(3,4,4,TOP_LAYER);
      M.plot(4,4,4,TOP_LAYER);
      M.plot(7,4,4,TOP_LAYER);
      M.plot(0,6,4,TOP_LAYER);
      M.plot(7,6,4,TOP_LAYER);
      M.plot(0,7,4,TOP_LAYER);
      M.plot(1,7,4,TOP_LAYER);
      M.plot(2,7,4,TOP_LAYER);
      M.plot(3,7,4,TOP_LAYER);
      M.plot(4,7,4,TOP_LAYER);
      M.plot(5,7,4,TOP_LAYER);
      M.plot(6,7,4,TOP_LAYER);
      M.plot(7,7,4,TOP_LAYER);
    }
    if (myChar == 'L'){
      M.clear();
      M.plot(1,1,1,TOP_LAYER);
      M.plot(2,1,1,TOP_LAYER);
      M.plot(5,1,1,TOP_LAYER);
      M.plot(6,1,1,TOP_LAYER);
      M.plot(0,2,1,TOP_LAYER);
      M.plot(1,2,1,TOP_LAYER);
      M.plot(2,2,1,TOP_LAYER);
      M.plot(3,2,1,TOP_LAYER);
      M.plot(4,2,1,TOP_LAYER);
      M.plot(5,2,1,TOP_LAYER);
      M.plot(6,2,1,TOP_LAYER);
      M.plot(7,2,1,TOP_LAYER);
      M.plot(0,3,1,TOP_LAYER);
      M.plot(1,3,1,TOP_LAYER);
      M.plot(2,3,1,TOP_LAYER);
      M.plot(3,3,1,TOP_LAYER);
      M.plot(4,3,1,TOP_LAYER);
      M.plot(5,3,1,TOP_LAYER);
      M.plot(6,3,1,TOP_LAYER);
      M.plot(7,3,1,TOP_LAYER);
      M.plot(1,4,1,TOP_LAYER);
      M.plot(2,4,1,TOP_LAYER);
      M.plot(3,4,1,TOP_LAYER);
      M.plot(4,4,1,TOP_LAYER);
      M.plot(5,4,1,TOP_LAYER);
      M.plot(6,4,1,TOP_LAYER);
      M.plot(2,5,1,TOP_LAYER);
      M.plot(3,5,1,TOP_LAYER);
      M.plot(4,5,1,TOP_LAYER);
      M.plot(5,5,1,TOP_LAYER);
      M.plot(3,6,1,TOP_LAYER);
      M.plot(4,6,1,TOP_LAYER);
    }
    if (myChar == 'A'){
      M.clear();
      M.plot(0,0,1,TOP_LAYER);
      M.plot(1,0,1,TOP_LAYER);
      M.plot(2,0,1,TOP_LAYER);
      M.plot(3,0,1,TOP_LAYER);
      M.plot(4,0,1,TOP_LAYER);
      M.plot(5,0,1,TOP_LAYER);
      M.plot(6,0,1,TOP_LAYER);
      M.plot(7,0,1,TOP_LAYER);
      M.plot(0,1,1,TOP_LAYER);
      M.plot(7,1,1,TOP_LAYER);
      M.plot(0,2,1,TOP_LAYER);
      M.plot(2,2,1,TOP_LAYER);
      M.plot(5,2,1,TOP_LAYER);
      M.plot(7,2,1,TOP_LAYER);
      M.plot(0,3,1,TOP_LAYER);
      M.plot(7,3,1,TOP_LAYER);
      M.plot(0,5,1,TOP_LAYER);
      M.plot(2,5,1,TOP_LAYER);
      M.plot(3,5,1,TOP_LAYER);
      M.plot(4,5,1,TOP_LAYER);
      M.plot(5,5,1,TOP_LAYER);
      M.plot(7,5,1,TOP_LAYER);
      M.plot(0,4,1,TOP_LAYER);
      M.plot(3,4,1,TOP_LAYER);
      M.plot(4,4,1,TOP_LAYER);
      M.plot(7,4,1,TOP_LAYER);
      M.plot(0,6,1,TOP_LAYER);
      M.plot(7,6,1,TOP_LAYER);
      M.plot(0,7,1,TOP_LAYER);
      M.plot(1,7,1,TOP_LAYER);
      M.plot(2,7,1,TOP_LAYER);
      M.plot(3,7,1,TOP_LAYER);
      M.plot(4,7,1,TOP_LAYER);
      M.plot(5,7,1,TOP_LAYER);
      M.plot(6,7,1,TOP_LAYER);
      M.plot(7,7,1,TOP_LAYER);
    }
    if (myChar == 'P'){
      M.clear();
      M.plot(0,0,2,TOP_LAYER);
      M.plot(1,0,2,TOP_LAYER);
      M.plot(2,0,2,TOP_LAYER);
      M.plot(3,0,2,TOP_LAYER);
      M.plot(4,0,2,TOP_LAYER);
      M.plot(5,0,2,TOP_LAYER);
      M.plot(6,0,2,TOP_LAYER);
      M.plot(7,0,2,TOP_LAYER);
      M.plot(0,1,2,TOP_LAYER);
      M.plot(7,1,2,TOP_LAYER);
      M.plot(0,2,2,TOP_LAYER);
      M.plot(2,2,2,TOP_LAYER);
      M.plot(5,2,2,TOP_LAYER);
      M.plot(7,2,2,TOP_LAYER);
      M.plot(0,3,2,TOP_LAYER);
      M.plot(7,3,2,TOP_LAYER);
      M.plot(0,5,2,TOP_LAYER);
      M.plot(2,5,2,TOP_LAYER);
      M.plot(3,5,2,TOP_LAYER);
      M.plot(4,5,2,TOP_LAYER);
      M.plot(5,5,2,TOP_LAYER);
      M.plot(7,5,2,TOP_LAYER);
      M.plot(0,4,2,TOP_LAYER);
      M.plot(7,4,2,TOP_LAYER);
      M.plot(0,6,2,TOP_LAYER);
      M.plot(7,6,2,TOP_LAYER);
      M.plot(0,7,2,TOP_LAYER);
      M.plot(1,7,2,TOP_LAYER);
      M.plot(2,7,2,TOP_LAYER);
      M.plot(3,7,2,TOP_LAYER);
      M.plot(4,7,2,TOP_LAYER);
      M.plot(5,7,2,TOP_LAYER);
      M.plot(6,7,2,TOP_LAYER);
      M.plot(7,7,2,TOP_LAYER);
    }
    if (myChar == 'T'){
      M.clear();
      M.plot(0,0,6,TOP_LAYER);
      M.plot(1,0,6,TOP_LAYER);
      M.plot(2,0,6,TOP_LAYER);
      M.plot(3,0,6,TOP_LAYER);
      M.plot(4,0,6,TOP_LAYER);
      M.plot(5,0,6,TOP_LAYER);
      M.plot(6,0,6,TOP_LAYER);
      M.plot(7,0,6,TOP_LAYER);
      M.plot(0,1,6,TOP_LAYER);
      M.plot(7,1,6,TOP_LAYER);
      M.plot(0,2,6,TOP_LAYER);
      M.plot(7,2,6,TOP_LAYER);
      M.plot(0,3,6,TOP_LAYER);
      M.plot(3,3,6,TOP_LAYER);
      M.plot(4,3,6,TOP_LAYER);
      M.plot(7,3,6,TOP_LAYER);
      M.plot(0,4,6,TOP_LAYER);
      M.plot(3,4,6,TOP_LAYER);
      M.plot(4,4,6,TOP_LAYER);
      M.plot(7,4,6,TOP_LAYER);
      M.plot(0,5,6,TOP_LAYER);
      M.plot(7,5,6,TOP_LAYER);
      M.plot(0,6,6,TOP_LAYER);
      M.plot(7,6,6,TOP_LAYER);
      M.plot(0,7,6,TOP_LAYER);
      M.plot(1,7,6,TOP_LAYER);
      M.plot(2,7,6,TOP_LAYER);
      M.plot(3,7,6,TOP_LAYER);
      M.plot(4,7,6,TOP_LAYER);
      M.plot(5,7,6,TOP_LAYER);
      M.plot(6,7,6,TOP_LAYER);
      M.plot(7,7,6,TOP_LAYER);
    }
  }
  
  //Lectura Serial
  if(impSerial.available()){
    myChar = impSerial.read();
    Serial.print(myChar);
    impSerial.println("Ack");
  }
 
}

void loop()
{
  myChar = 'T';
  M.set_cur(0,0);   
  M.display(hook);
}
