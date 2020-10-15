///
/// DISCLAIMER: <windows.h> must be included
///
#include <windows.h>

/// SYMBOLIC CONSTANTS

#define CUI_DEFAULT_CURSORX 0
#define CUI_DEFAULT_CURSORY 1

#define CUI_COLOR_CONTRAST 'F', '0'
#define CUI_COLOR_ERROR 'F', 'E'
#define CUI_COLOR_BLUESCREEN '0', '7'
#define CUI_COLOR_DEBUG '4','4'

#define CUI_DEFAULT_BORDERWIDTH 65
#define CUI_DEFAULT_BORDERHEIGTH 18

#define CUI_DEFAULT_SUBBORDERWIDTH 10
#define CUI_DEFAULT_SUBBORDERHEIGHT 3


/// FUNCTIONS

// Sets up the console. Sets codepage and clears it
void cui_setUp();

// Sets cursor to specific position
///@param xCoord x-Coordinate
///@param yCoord y-Coordinate
int cui_setCursor(int xCoord, int yCoord);

// Resets the cursor to the default position
int cui_resetCursor();

// Sets the back- and foreground color of the console
int cui_setColor(char colorCodeBackground, char colorCodeForeground);

// Resets the color pattern to black and white
int cui_resetColor();

// Creates a border with specific width and height
void cui_createBorder(int borderWidth, int borderHeight);

// Creates a 65 * 18 border
void cui_createStdBorder();

// Creates a border of specific size at the specific position
void cui_createSmallBorder(int cursorXCoord, int cursorYCoord, int borderWidth, int borderHeight);

// Clears the console
void cui_clear();


/// MACROS

#define cursorTo(x,y) cui_setCursor(x,y)
#define resetCursor cui_resetCursor()
#define Border(x,y) cui_createBorder(x,y)
#define StdBorder cui_createStdBorder()
#define SmallBorder(x,y,a,b) cui_createSmallBorder(x,y,a,b)
#define clear cui_clear()
