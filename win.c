#include <stdio.h>
#include "win.h"
#include "GetMove.h"
#include "Board.h"

bool isGameOver(Board board, int num_win, InputWindow* inputWindow) {
    return win(board, num_win) || tie(board, num_win);
}

bool win(Board board, int num_win) {
    return horzWin(board, num_win) || vertWin(board, num_win) || diagWin(board, num_win);
}

bool horzWin(Board board, int num_win) {
    int numInARow;
    for (int row = 0; row < board.numRows; row++) {
        numInARow = 0;
        for (int col = 0; col < board.numCols -1; col++) {
            if (board.theBoard[row][col] == board.blankChar) {
                numInARow = 0;
                continue;
            }
            if (board.theBoard[row][col+1] == board.theBoard[row][col]) {
                numInARow++;
                if (numInARow == num_win -1 ) {
                    return true;
                }
            }
            else {
                numInARow = 0;
                continue;
            }
        }
    }
    return false;
}

bool vertWin(Board board, int num_win) {
    int numInARow;
    for (int col = 0; col < board.numCols; ++col) {
        numInARow = 0;
        for (int row = 0; row < board.numRows - 1; ++row) {
            if (board.theBoard[row][col] == board.blankChar) {
                numInARow = 0;
                continue;
            }
            if (board.theBoard[row+1][col] == board.theBoard[row][col]) {
                numInARow++;
                if (numInARow == num_win - 1) {
                    return true;
                }
            } else {
                numInARow = 0;
                continue;
            }
        }
    }
    return false;
}

bool diagWin(Board board, int num_win) {
    return leftDiagWin(board, num_win) || rightDiagWin(board, num_win);
}


bool leftDiagWin(Board board, int num_win) {
    int numInARow;

    for (int row = 0; row < board.numRows - num_win + 1; ++row) {
        numInARow = 0;
        for (int col = 0; col < board.numCols - num_win + 1; col++){
            if (board.theBoard[row][col] == board.blankChar){
                numInARow = 0;
                continue;
            }
            if (board.theBoard[row][col] == board.theBoard[row+1][col+1]){
                for (int i = 0; i < num_win - 1; i++){
                    if (board.theBoard[row + i][col + i] == board.theBoard[row + 1 + i][col+ 1 + i]){
                        numInARow++;
                    } else{
                        break;
                    }
                }

            }
            if(numInARow == num_win - 1){
                return true;
            }
            else{
                numInARow = 0;
                continue;
            }
        }
    }

    return false;

}
bool rightDiagWin(Board board, int num_win) {
    int numInARow;

    for (int row = 0 ; row < board.numRows - num_win + 1; ++row) {
        numInARow = 0;
        for (int col = num_win - 1; col < board.numCols; col++){
            if (board.theBoard[row][col] == board.blankChar){
                numInARow = 0;
                continue;
            }
            if (board.theBoard[row][col] == board.theBoard[row + 1][col - 1]){
                for (int i = 0; i < num_win - 1; i++){
                    if (board.theBoard[row + i][col - i] == board.theBoard[row + 1 + i][col- 1 - i]){
                        numInARow++;
                    } else{
                        break;
                    }
                }

            }
            if(numInARow == num_win - 1){
                return true;
            }

            else{
                numInARow = 0;
                continue;
            }
        }
    }

    return false;
}

bool tie(Board board, int num_win) {

    if(win(board, num_win)){
        return false;
    }


    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if(board.theBoard[row][col] == board.blankChar){
                return false;
            }
        }
    }
    return true;
}

int declareWinner(Board board, TurnType playerTurn, int num_win) {
    int winner;
    if(win(board, num_win)){
        //if someone one it would actually be the loser's turn
        //so account for this here
        winner = playerTurn == Player1 ? Player2 : Player1;
        winner++;}
    else{
        winner = 3;}
    return winner;
}
