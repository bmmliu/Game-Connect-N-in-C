//
// Created by BMM Liu on 2/7/19.
//


#include "InputWindow.h"

InputWindow MakeInputWindow(int numRows, int numCols, int rowStart, int colStart){
    InputWindow inputwindow;
    inputwindow.inputWin = newwin(numRows,numCols,rowStart,colStart);
    inputwindow.inputRow= rowStart;
    inputwindow.inputCol = 0;
    return inputwindow;
}

void fillinputWindow(InputWindow* inputwindow, char blank_space){
    for(int i = 0; i < getmaxy(inputwindow->inputWin); ++i){
        for(int j = 0; j < getmaxx(inputwindow->inputWin); ++j){
            mvwaddch(inputwindow->inputWin, i, j, blank_space);
        }

    }
    wmove(inputwindow->inputWin, 0, 0); //move the cursor to (0,0)//
}