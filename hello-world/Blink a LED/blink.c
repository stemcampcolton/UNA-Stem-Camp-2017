/*
*Colton Gooch
*program #2
*06/12/17
*Blink a LED
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{

  while(1)
  {
    high(0);
    pause(1);
    low(0);
    pause(1);
    high(10);
    pause(1);
    low(10);
    pause(1);
  }  
}
