//
// Created by BMM Liu on 2/7/19.
//

#ifndef CONNECTN_WIN_H
#define CONNECTN_WIN_H
#include <stdbool.h>
#include "Board.h"
#include "GetMove.h"

bool isGameOver(Board board, int num_win, InputWindow* inputWindow);
bool win(Board board, int num_win);
bool horzWin(Board board,int num_win);
bool vertWin(Board board,int num_win);
bool diagWin(Board board,int num_win);
bool leftDiagWin(Board board,int num_win);
bool rightDiagWin(Board board,int num_win);
bool tie(Board board, int num_win);
int declareWinner(Board board, TurnType playerTurn, int num_win);
#endif //CONNECTN_WIN_H
