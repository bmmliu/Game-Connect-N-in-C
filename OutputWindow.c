//
// Created by Yifan Liu on 2019-02-05.
//

#include "OutputWindow.h"
#include "win.h"
#include "Board.h"
#include "GetMove.h"

OutputWindow MakeOutPutWindow(int numRows, int numCols, int rowStart, int colStart){
    OutputWindow outputwindow;
    outputwindow.outputWin = newwin(numRows,numCols,rowStart,colStart);
    outputwindow.outputRow= rowStart;
    outputwindow.outputCol = 0;
    return outputwindow;
}

void filloutputWindow(OutputWindow* outputwindow, char blank_space){
    for(int i = 0; i < getmaxy(outputwindow->outputWin); ++i){
        for(int j = 0; j < getmaxx(outputwindow->outputWin); ++j){
            mvwaddch(outputwindow->outputWin, i, j, blank_space);

        }
    }
}

void declareWinnerInTheWindow(OutputWindow* outputwindow, Board board, TurnType playerTurn, int num_win, FILE *fp){
    int winner;
    winner = declareWinner(board, playerTurn, num_win);
    if(winner == 1) {
        char* announcement = "Player 1 won!";
        for (int j = 0; j < 14; ++j) {
            mvwaddch(outputwindow->outputWin, 0, j, announcement[j]);
            fputc(announcement[j], fp);
        }
    }
    else if(winner == 2){
        char* announcement = "Player 2 won!";
        for (int j = 0; j < 14; ++j) {
            mvwaddch(outputwindow->outputWin, 0, j, announcement[j]);
            fputc(announcement[j], fp);
        }
    }
    else{
        char* announcement = "Tie game";
        for (int j = 0; j < 8; ++j) {
            mvwaddch(outputwindow->outputWin, 0, j, announcement[j]);
            fputc(announcement[j], fp);
        }

    }
    wrefresh(outputwindow->outputWin);
}
