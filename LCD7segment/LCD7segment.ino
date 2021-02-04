//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 10 is connected to the DataIn 
 pin 12 is connected to the CLK 
 pin 11 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(10,12,11,1);  // 1 = 1 LED device

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;
int i=0;
int j=0;
int b1_pin=9;
int b2_pin=8;
int b1_state=0;
int b2_state=0;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,5);
  /* and clear the display */
  lc.clearDisplay(0);
  pinMode(b1_pin, INPUT);
  pinMode(b2_pin, INPUT);
}

void loop() {

/*  for(int i=0;i<10;i++) {
    lc.setDigit(0,3,i,false);
    lc.setDigit(0,2,i,false);
    lc.setDigit(0,1,i,false);
    lc.setDigit(0,0,i,false);
    delay(delaytime);
  }
  lc.clearDisplay(0);
  delay(delaytime);
  }
*/
  b1_state = digitalRead(b1_pin);
  b2_state = digitalRead(b2_pin);
  if(b1_state == LOW) {    
    i++;
    if(i>=10) {
      i=0;
      j++;
    }
    delay(500);
  }
  if(b2_state == LOW) {
    i--;
    if(i<0) {
      i=9;
      j--;
    }
    delay(500);
  }
  lc.setDigit(0,3,i,false);
  if(j>0) {
    lc.setDigit(0,2,j,false);
  }

}
