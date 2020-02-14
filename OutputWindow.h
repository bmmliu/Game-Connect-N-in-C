//
// Created by BMM Liu on 2/7/19.
//

#ifndef CONNECTN_OUTPUTWINDOW_H
#define CONNECTN_OUTPUTWINDOW_H
#include "ncurses.h"
#include "win.h"
typedef struct outputwin_Struct{
    WINDOW* outputWin;
    int outputRow, outputCol;
}OutputWindow;
OutputWindow MakeOutPutWindow(int numRows, int numCols, int rowStart, int colStart);
void filloutputWindow(OutputWindow* outputwindow, char blank_space);
void declareWinnerInTheWindow(OutputWindow* outputwindow, Board board, TurnType playerTurn, int num_win, FILE *fp);
#endif //CONNECTN_OUTPUTWINDOW_H
