//
// Created by BMM Liu on 2/7/19.
//

#ifndef CONNECTN_GETMOVE_H
#define CONNECTN_GETMOVE_H
#include "stdbool.h"
#include "Board.h"
#include "CursortrackedWindow.h"
#include "InputWindow.h"
typedef struct Move_Struct{
    int row, col;
    char marker;
}Move;

typedef enum{Player1 = 0, Player2 = 1}
        TurnType;



Move getValidMove(Board* board, TurnType playerturn, InputWindow* inputWindow,  CursorTrackedWindow* win, const int numrows, const int numcols, FILE *fp);
bool isValidMove(Move move, struct Board_Struct* board, int numArgsRead, int numArgsNeeded);
void placeMove(Move move, Board* board, CursorTrackedWindow* win, InputWindow* inputWindow, FILE *fp);
#endif //CONNECTN_GETMOVE_H
