/** Sample Program using CUI **/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "CUI.h"

int main(void){
  char* name[30] = "";
  
  cui_setUp();
  
  // Creating a border
  cui_resetCursor();
  cui_createBorder(65, 20);
  
  // Creating a smaller border for input
  cui_setCursor(2,2);
  printf("Enter your name");
  cui_createSmallBorder(2,3,32,3);
  
  // User input
  cui_setCursor(3,4);
  gets(name);
  
  // Output
  cui_setCursor(2,6);
  cui_setColor(CUI_COLOR_BLUESCREEN);
  printf("Hello, %s :)", name);
  cui_resetColor();
  
  // Setting cursor outside of border to prevent
  // clipping of termination message
  cui_setCursor(0,22);
  
  return 0;
}
