//
// Created by BMM Liu on 2/7/19.
//
#include <stdlib.h>
#include <stdio.h>
#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H
typedef struct Board_Struct{
    char** theBoard;
    int numRows;
    int numCols;
    char blankChar;
}Board;

Board makeBoard(int numRows, int numCols, char blankChar);
void printBoard(Board board, FILE *fp);
void cleanUpBoard(Board* board);
#endif //CONNECTN_BOARD_H
