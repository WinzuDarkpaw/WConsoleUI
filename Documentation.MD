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
>Definition
```C
void cui_init()
{
  system("chcp 437");
  system("cls");
}
```

# Symbolic Constants
### CUI_COLOR_BLUESCREEN
- Is only usable inside the CUI Functions or functions which uses two chars as parameters
>Example
```C
  cui_setColor(CUI_COLOR_BLUESCREEN);
  //print out something
  cui_resetColor();
```
>Definition
```C
#define CUI_COLOR_BLUESCREEN '4', '4'
```
# Macros
### border(x,y)
- Macro for cui_createBorder(int height, int width)
>Example
```C
  //Some code
  border(65, 18);
  //Some more code
```
>Definition
```C
#define border(x,y) cui_createBorder(x,y)
```
