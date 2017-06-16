/*
  * Colton Gooch
  * Program 9
  * receive text over the wireless radio
  * 06/16/17
*/
#include "simpletools.h"                      // Include simple tools
#include "fdserial.h"

void init_radio(fdserial *radio);

int main()                                    // Main function
{
  // Add startup code here.
  char c;
  fdserial *xbee;
  
  // check to make sure the sender program is running on anther board
  print("This board will receive massage via wireless.\n");
  print("You MUST start the other program on the other board first.\n");
  while(c != 'Y' || c != 'y')
  {
    print("Is the other end started");
    scan("%c", &c);
  }    
  // open a serial connection to the xbee radio
  xbee = fdserial_open(0 ,1, 0, 9600);
  
  
  init_radio(xbee);
 
  // clear the sender's sceen and tell them it is ok to start typing
  fdserial_txChar(xbee, CLS);
  dprint(xbee, "Connection estadished!\n");
  dprint(xbee, "Click on this screen and type your massage.\n");
  
  // get a charater from the screen and send it over the radio
  while(1)
  {
    c = fdserial_rxChar(xbee);
    if (c != 255)
    {
     print("%c", c);
    }  
  }    
}

void init_radio(fdserial *radio)
{
  const char channel = 'F';         // 0x0B to 0x1A, must match your partner
  const char PAN_ID[] = "AAAA";    // 0x0 to 0xFFFF, must match your partner
  const char DEST_ID[] = "0002";   // 0x0 to 0xFFFF, must be your partner's SRC_ID
  const char SRC_ID[] = "0001" ;    // 0x0 to 0xFFFF, must be your partner's DEST_ID
  
  char result[32] = {0};
  
  dprint(radio, "+++");
  pause(50);
  dscan(radio, "%s", &result);
  print("Radio initialization: %s\n", result);
  pause(50);
  
  dprint(radio, "ATRE\n");
  dprint(radio, "ATCH%c\n", channel);
  dprint(radio, "ATID%s\n", PAN_ID);
  dprint(radio, "ATDL%s\n", DEST_ID);
  dprint(radio, "ATMY%s\n", SRC_ID);
  dprint(radio, "ATAC\n");
  dprint(radio, "ATCN\n");
  pause(500);
  print("\n");
}  