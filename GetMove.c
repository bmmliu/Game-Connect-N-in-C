//
// Created by BMM Liu on 2/7/19.
//
#include "GetMove.h"
#include <stdio.h>
#include "Board.h"
#include "InputWindow.h"
#include "CursortrackedWindow.h"

Move getValidMove(Board* board, TurnType playerTurn, InputWindow* inputwindow, CursorTrackedWindow* win, const int numrows, const int numcols, FILE *fp) {

    Move move;
    while (true) {
        char input = wgetch(inputwindow->inputWin);
        if (input == 'a' || input == 'j') {
            mvwaddch(inputwindow->inputWin, 0, inputwindow->inputCol, '_');
            if (inputwindow->inputCol > 0) {
                inputwindow->inputCol -= 1;
                mvwaddch(inputwindow->inputWin, 0, inputwindow->inputCol, "XO"[playerTurn]);
                wmove(inputwindow->inputWin, inputwindow->inputRow, inputwindow->inputCol);
                wrefresh(inputwindow->inputWin);
                for(int i = 0 ; i < inputwindow->inputCol; i++){
                    fputc('_', fp);
                }
                fputc("XO"[playerTurn], fp);
                fputc('\n', fp);
                printBoard(*board, fp);
            }
            else{
                inputwindow->inputCol = numcols -1;
                mvwaddch(inputwindow->inputWin, 0, inputwindow->inputCol, "XO"[playerTurn]);
                wmove(inputwindow->inputWin, inputwindow->inputRow, inputwindow->inputCol);
                wrefresh(inputwindow->inputWin);
                for(int i = 0 ; i < inputwindow->inputCol; i++){
                    fputc('_', fp);
                }
                fputc("XO"[playerTurn], fp);
                fputc('\n', fp);
                printBoard(*board, fp);
            }
        }
        else if (input == 's' || input == 'k') {
            mvwaddch(inputwindow->inputWin, 0, inputwindow->inputCol, '_');
            if (inputwindow->inputCol < numcols - 1) {
                inputwindow->inputCol += 1;
                mvwaddch(inputwindow->inputWin, 0, inputwindow->inputCol, "XO"[playerTurn]);
                wmove(inputwindow->inputWin, inputwindow->inputRow, inputwindow->inputCol);
                wrefresh(inputwindow->inputWin);
                for(int i = 0 ; i < inputwindow->inputCol; i++){
                    fputc('_', fp);
                }
                fputc("XO"[playerTurn], fp);
                fputc('\n', fp);
                printBoard(*board, fp);
            }
            else{
                inputwindow->inputCol = 0;
                mvwaddch(inputwindow->inputWin, 0, inputwindow->inputCol, "XO"[playerTurn]);
                wmove(inputwindow->inputWin, inputwindow->inputRow, inputwindow->inputCol);
                wrefresh(inputwindow->inputWin);
                for(int i = 0 ; i < inputwindow->inputCol; i++){
                    fputc('_', fp);
                }
                fputc("XO"[playerTurn], fp);
                fputc('\n', fp);
                printBoard(*board, fp);
            }

        }
        else if (input == ' ' || input == '\n'){
            for(int i=board->numRows - 1; i>=0; i--){
                if(board->theBoard[i][inputwindow->inputCol] == board->blankChar){
                    move.row = i;
                    move.col = inputwindow->inputCol;
                    move.marker = "XO"[playerTurn];
                    wrefresh(inputwindow->inputWin);

                    return move;
                }
            }

        }

    }

}

void placeMove(Move move, Board* board, CursorTrackedWindow* win, InputWindow* inputWindow, FILE *fp){

    board->theBoard[move.row][move.col] = move.marker;
    mvwaddch(win->cursesWin, move.row, move.col, move.marker);
    wmove(inputWindow->inputWin, inputWindow->inputRow, inputWindow->inputCol);
    wrefresh(win->cursesWin);
    wrefresh(inputWindow->inputWin);

}
