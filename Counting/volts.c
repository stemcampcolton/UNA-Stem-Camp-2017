/*
  *Colton Gooch
  *Program #4
  *Mearure voltage using a potentiometer
  *06/13/17
*/
#include "simpletools.h"                      // Include simple tools
#include "adcDCpropab.h"
int main()                                    // Main function
{
  // Add startup code here.
  adc_init(21, 20, 19, 18);
 float volts;
 
 
  while(1)
  {
    // Add main loop code here.
    volts = adc_volts(3);
    putChar(HOME);
    print("A/D Channel 3 =%0.5f Volts %c\n", volts, CLREOL);
    pause(100);
    
    high(15);
    pause(volts*100+10);
    low(15);
    pause(volts*100+10);
  }  
}
