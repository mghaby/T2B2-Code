#include <LedControl.h>
// https://www.youtube.com/watch?v=NEXjteud3is for any explanations
int DIN = 12;
int CS = 11;
int CLK = 10;

byte face[8] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100};
  
/* 0 - 9 , A - F
  B01110000,  //0
      B10001000,
      B10011000,
      B10101000,
      B11001000,
      B10001000,
      B01110000,

   
      B01000000,  //1
      B11000000,
      B01000000,
      B01000000,
      B01000000,
      B01000000,
      B11100000,

   
      B01110000,  //2
      B10001000,
      B00001000,
      B00010000,
      B00100000,
      B01000000,
      B11111000,

   
      B11111000,  //3
      B00010000,
      B00100000,
      B00010000,
      B00001000,
      B10001000,
      B01110000,

   
      B00010000,  //4
      B00110000,
      B01010000,
      B10010000,
      B11111000,
      B00010000,
      B00010000,

   
      B11111000,  //5
      B10000000,
      B11110000,
      B00001000,
      B00001000,
      B10001000,
      B01110000,

   
      B00110000,  //6
      B01000000,
      B10000000,
      B11110000,
      B10001000,
      B10001000,
      B01110000,

   
      B11111000,  //7
      B10001000,
      B00001000,
      B00010000,
      B00100000,
      B00100000,
      B00100000,

   
      B01110000,  //8
      B10001000,
      B10001000,
      B01110000,
      B10001000,
      B10001000,
      B01110000,

   
      B01110000,  //9
      B10001000,
      B10001000,
      B01111000,
      B00001000,
      B00010000,
      B01100000,

      B01110000,  //A
    B10001000,
    B10001000,
    B10001000,
    B11111000,
    B10001000,
    B10001000,

 
    B11110000,  //B
    B10001000,
    B10001000,
    B11110000,
    B10001000,
    B10001000,
    B11110000,

 
    B01110000,  //C
    B10001000,
    B10000000,
    B10000000,
    B10000000,
    B10001000,
    B01110000,

 
    B11100000,  //D
    B10010000,
    B10001000,
    B10001000,
    B10001000,
    B10010000,
    B11100000,
 
 
    B11111000,  //E
    B10000000,
    B10000000,
    B11110000,
    B10000000,
    B10000000,
    B11111000,

 
    B11111000,  //F
    B10000000,
    B10000000,
    B11110000,
    B10000000,
    B10000000,
    B10000000,
  
*/

LedControl lc(DIN, CLK, CS, 1);

void setup(){
  lc.shutdown(0,false);
  lc.setIntensity( 0,8);
  lc.clearDisplay(0);
  
}


void loop(){
  DisplayBytes(face);
}

void DisplayBytes(byte image[]){
  for(int i = 0; i <= 7; i++){
    lc.setRow(0, i, face[i]
  }
}
