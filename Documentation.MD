# Functions
### cui_init()
>Example
```C
#include "CUI.h"

int main(void){
  cui_init();
}
```

- Changes the codepage to get the correct characters to draw proper borders
- Clears the console

### cui_setCursor(int, int)
>Example
```C
  cui_setCursor(1,1); // Sets the cursor to x=1, y=1
  scanf("%c", &someChar);
  cui_setCursor(1,2); // Sets the cursor to x=1, y=2
  printf("Your char was %c", someChar);
```
- Sets the cursor to a certain position in the console
- Point x=0, y=0 represents the upper left point in the console
- Therefor, *cui_setCursor(5,5)* sets the Cursor 5 places to the right and 5 places down (from the point x=0, y=0)

### cui_resetCursor()
>Example
```C
  // some code
  cui_resetCursor();
```
>Equivalant to
```C
  // some code
  cui_setCursor(0,0);
```
- Sets the cursor to the (in the header file defined) default position.
See [CUI_DEFAULT_CURSORX](https://github.com/WinzuDarkpaw/WConsoleUI/blob/main/Documentation.MD#cui_default_cursorx) or [CUI_DEFAULT_CURSORY](https://github.com/WinzuDarkpaw/WConsoleUI/blob/main/Documentation.MD#cui_default_cursory)

### cui_setColor(char, char)
>Example
```C
  // some code
  cui_setColor('F', 'F');
  printf("foo");
  // different code
```
- Sets the color of the back- and foreground of the console
- Reset to default color with [cui_resetColor](https://github.com/WinzuDarkpaw/WConsoleUI/blob/main/Documentation.MD#cui_resetcolor)

### cui_resetColor()
>Example
```C
  cui_setColor('F', 'F');
  printf("foo");
  cui_resetColor();
```
- Resets the set color to the default console black and white color pallet

### cui_createBorder(int, int)
>Example
```C
  cui_createBorder(15, 3);
  // Write Text inside border (without replacing border)
  cui_setCursor(1,1);
  printf("Hello, world!");
  // further code
```
- Creates a border with width x and height y
- The first parameter is the width, the second parameter is the height
- The upper left corner of the border is the current point of the cursor
  - But it will cause issues to the border when the cursor position is not X=0

### cui_createStdBorder()
>Example
```C
  cui_createStdBorder();
  // some code
```
- Creates a border with a (in the header file defined) standard width and height
- The upper left corner of the border is the current point of the cursor
  - But it will cause issues to the border when the cursor position is not X=0
  
### cui_createSmallBorder(int, int, int, int)
```C
  // previous code
  cui_createSmallBorder(3,3,10,5);
  // Write something into the border
  cui_setCursor(4,4);
  printf("foo");
  // further code
```
- Creates a border with a width of a and a height of b at the point x and y
- Parameter one is the point x, two is the point y, three is the width a and four is the height b

### cui_clear()
```C
  // previous code
  cui_clear();
  // further code, maybe create a new border (use it as a window for example)
````
- Clears the console

# Symbolic Constants
### CUI_DEFAULT_CURSORX
>Example
```C
  cui_setCursor(CUI_DEFAULT_CURSORX, 3);
```
>Definition
```C
#define CUI_DEFAULT_CURSORX 0
```
- Defines the default X-Coordinate of the cursor
### CUI_DEFAULT_CURSORY
>Example
```C
  cui_setCursor(5, CUI_DEFAULT_CURSORY);
```
>Definition
```C
#define CUI_DEFAULT_CURSORY 0
```
- Defines the default Y-Coordinate of the cursor

### CUI_COLOR_BLUESCREEN
>Example
```C
  cui_setColor(CUI_COLOR_BLUESCREEN);
  // print out something
  cui_resetColor();
```
>Definition
```C
  // TODO
```
- Is only usable inside the CUI Functions or functions which uses two chars as parameters

### CUI_COLOR_ERROR
>Example
```C
  cui_setColor(CUI_COLOR_ERROR);
  // print out something
  cui_resetColor();
```
>Definition
```C
  // TODO
```
- Is only usable inside the CUI Functions or functions which uses two chars as parameters

### CUI_COLOR_DEBUG
>Example
```C
  cui_setColor(CUI_COLOR_DEBUG);
  // print out something
  cui_resetColor();
```
>Definition
```C
  // TODO
```
- Is only usable inside the CUI Functions or functions which uses two chars as parameters

### CUI_COLOR_CONTRAST
>Example
```C
  cui_setColor(CUI_COLOR_CONTRAST);
  // print out something
  cui_resetColor();
```
>Definition
```C
  // TODO
```
- Is only usable inside the CUI Functions or functions which uses two chars as parameters

# Macros
### border(x,y)
- Macro for cui_createBorder(int height, int width)
>Example
```C
  // Some code
  border(65, 18);
  // Some more code
```
>Definition
```C
#define border(x,y) cui_createBorder(x,y)
```
