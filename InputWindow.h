//
// Created by BMM Liu on 2/7/19.
//

#ifndef CONNECTN_INPUTWINDOW_H
#define CONNECTN_INPUTWINDOW_H
#include <ncurses.h>
typedef struct inputWin_Struct{
    WINDOW* inputWin;
    int inputRow, inputCol;
}InputWindow;
InputWindow MakeInputWindow(int numRows, int numCols, int rowStart, int colStart);
void fillinputWindow(InputWindow* inputwindow, char blank_space);
#endif //CONNECTN_INPUTWINDOW_H
