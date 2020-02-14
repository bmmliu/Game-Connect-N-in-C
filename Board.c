#include "Board.h"
#include <stdio.h>
#include <stdlib.h>

Board makeBoard(int numRows, int numCols, char blankChar){
    Board board;

    board.theBoard = (char**)malloc(numRows * sizeof(char*));
    for(int i = 0; i < numRows; i++){
        board.theBoard[i] =(char*) malloc(numCols * sizeof(char));
        for(int j = 0; j < numCols; j++){
            board.theBoard[i][j] = blankChar;
        }
    }
    board.numRows = numRows;
    board.numCols = numCols;
    board.blankChar = blankChar;
    return board;

}

void printBoard(Board board, FILE *fp){
    for(int i = 0; i < board.numRows; i++){
        for(int j = 0; j < board.numCols; j++) {
            fputc(board.theBoard[i][j], fp);
        }
        fputc('\n', fp);
    }
    fputc('\n', fp);
    fputc('\n', fp);
}

void cleanUpBoard(Board* board){
    for(int i = 0; i < board-> numRows; ++i) {
        free(board->theBoard[i]);
    }
    free(board->theBoard);
    board->theBoard = NULL;
    board->numRows = 0;
    board->numCols = 0;
}
