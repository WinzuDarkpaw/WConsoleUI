/** https://github.com/WinzuDarkpaw/WConsoleUI **/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "CUI.h"

void cui_setUp()
{
    system("chcp 437");
    system("cls");
}

int cui_setCursor(int xCoord, int yCoord)
{
    COORD coord;
    coord.X = xCoord;
    coord.Y = yCoord;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0;
}

int cui_resetCursor()
{
    COORD coord;
    coord.X = CUI_DEFAULT_CURSORX;
    coord.Y = CUI_DEFAULT_CURSORY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0;
}

int cui_setColor(char colorCodeBackground, char colorCodeForeground)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (colorCodeForeground | colorCodeBackground));
    return 0;
}

int cui_resetColor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(handle,&csbi);
    SetConsoleTextAttribute(handle, 0x0f);
    return 0;
}

void cui_createBorder(int borderWidth, int borderHeight)
{
    int i, j;

    for(i = 0; i < borderHeight; i++)
    {
        for(j = 0; j < borderWidth; j++)
        {
            if(i == 0 && j == 0)
            {
                printf("\xC9");
            }
            else if(i == 0 && j == borderWidth - 1)
            {
                printf("\xBB");
            }
            else if(i == borderHeight - 1 && j == 0)
            {
                printf("\xC8");
            }
            else if(i == borderHeight - 1 && j == borderWidth - 1)
            {
                printf("\xBC");
            }
            else if(i == 0 || i == borderHeight - 1)
            {
                printf("\xCD");
            }
            else if(j == 0 || j == borderWidth - 1)
            {
                printf("\xBA");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void cui_createStdBorder()
{
    int i, j;

    int borderHeight = CUI_DEFAULT_BORDERHEIGTH;
    int borderWidth = CUI_DEFAULT_BORDERWIDTH;

    for(i = 0; i < borderHeight; i++)
    {
        for(j = 0; j < borderWidth; j++)
        {
            if(i == 0 && j == 0)
            {
                printf("\xC9");
            }
            else if(i == 0 && j == borderWidth - 1)
            {
                printf("\xBB");
            }
            else if(i == borderHeight - 1 && j == 0)
            {
                printf("\xC8");
            }
            else if(i == borderHeight - 1 && j == borderWidth - 1)
            {
                printf("\xBC");
            }
            else if(i == 0 || i == borderHeight - 1)
            {
                printf("\xCD");
            }
            else if(j == 0 || j == borderWidth - 1)
            {
                printf("\xBA");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void cui_createSmallBorder(int cursorX, int cursorY, int borderWidth, int borderHeight)
{
    int i, j;

    int cursorYOffset = 1;
    cui_setCursor(cursorX, cursorY);
    for(i = 0; i < borderHeight; i++)
    {
        for(j = 0; j < borderWidth; j++)
        {
            if(i == 0 && j == 0)
            {
                printf("\xC9");
            }
            else if(i == 0 && j == borderWidth - 1)
            {
                printf("\xBB");
            }
            else if(i == borderHeight - 1 && j == 0)
            {
                printf("\xC8");
            }
            else if(i == borderHeight - 1 && j == borderWidth - 1)
            {
                printf("\xBC");
            }
            else if(i == 0 || i == borderHeight - 1)
            {
                printf("\xCD");
            }
            else if(j == 0 || j == borderWidth - 1)
            {
                printf("\xBA");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        cui_setCursor(cursorX, cursorY + cursorYOffset);
        cursorYOffset++;
    }
    cui_setCursor(0, CUI_DEFAULT_BORDERHEIGTH + 1);
}

void cui_clear()
{
    system("cls");
}
