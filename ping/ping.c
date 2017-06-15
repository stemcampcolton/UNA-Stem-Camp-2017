/*
 * Colton Gooch
 * 
*/
#include "simpletools.h"                      // Include simple tools

const int TIGGER_PIN = 0;
const int ECHO_PIN = 1;

int main()                                    // Main function
{
  long duration;
  long distance;
  
  low(TRIGGER_PIN);
  low(ECHO_PIN);
 
  while(1)
  {
    pulse_out(TIGGER_PIN, 10);
    duration = pulse_in(ECHO_PIN, 1);
    print("%c%c", HOME, CLREOL);
    distance = duration / 148;
    print("Distance = %d inches\n", distance);
    pause(250);
  }  
}
