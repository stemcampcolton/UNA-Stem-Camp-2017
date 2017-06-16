/*
  * Colton Gooch
  * Program 9
  * Send text over the wireless radio
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
  
  // open a serial connection to the xbee radio
  xbee = fdserial_open(0 ,1, 0, 9600);
  init_radio(xbee);
  print("Waiting for the receiver to start their program...\n");
  c = fdserial_rxChar(xbee);
  while (c != 255)
  {
    pause(5);
    c = fdserial_rxChar(xbee);
  }       
  
  // get a charater from the screen and send it over the radio
  while(1)
  {
    c = getChar();
    fdserial_txChar(xbee , c);
  }  
}

void init_radio(fdserial *radio)
{
  const char channel = 'B';         // 0x0B to 0x1A, must match your partner
  const char PAN_ID[] = "AAAA";    // 0x0 to 0xFFFF, must match your partner
  const char DEST_ID[] = "0001";   // 0x0 to 0xFFFF, must be your partner's SRC_ID
  const char SRC_ID[] = "0002" ;    // 0x0 to 0xFFFF, must be your partner's DEST_ID
  
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