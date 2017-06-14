/*
 * Colton Gooch
 * Use a button to turn on and off a LED
 * Program 5
 * 06/14/17
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  // Add startup code here.

 
  while(1)
  {
    if ( input(0) == 0 )
    {
      putChar(HOME);
      print("The button is pressed %c\n", CLREOL);
      high(26);
      low(27);
    }
    else
    {
      putChar(HOME);
      print("The botton is not pressed %c\n", CLREOL);
      low(26);
      high(27);
    }
    pause(100);
  }  
}
