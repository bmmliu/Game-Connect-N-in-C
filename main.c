#include <stdio.h>
#include <ncurses.h>
#include "win.h"
#include "InputWindow.h"
#include "OutputWindow.h"
#include "win.h"
#include "CursortrackedWindow.h"
#include "GetMove.h"
#include <stdlib.h>

int main(int argc,char *argv[]) {
    initscr();
    noecho();
    cbreak();
    int board_row = atoi(argv[1]);
    int board_col = atoi(argv[2]);
    int num_win = atoi(argv[3]);
    FILE *fp = fopen(argv[4], "w");
    InputWindow inputwindow = MakeInputWindow(1, board_col, 0, 0);
    fillinputWindow(&inputwindow, '_');
    CursorTrackedWindow cursortrackedWindow = makenewCursorTrackedWindow(board_row,board_col,1,0);
    fillWindow(&cursortrackedWindow, '*');
    OutputWindow outputwindow = MakeOutPutWindow(1, 14, board_row+1, 0);
    filloutputWindow(&outputwindow, '_');
    Board board = makeBoard(board_row, board_col, '*');
    TurnType playerTurn = Player1;
    mvwaddch(inputwindow.inputWin, 0, 0, "XO"[playerTurn]);
    wmove(inputwindow.inputWin, 0, 0);
    wrefresh(outputwindow.outputWin);
    wrefresh(cursortrackedWindow.cursesWin);
    wrefresh(inputwindow.inputWin);

    while(!isGameOver(board, num_win , &inputwindow)){
        for(int i = 0 ; i < inputwindow.inputCol; i++){
            fputc('_', fp);
        }
        if(playerTurn == 0){
            fputc('X', fp);
        }
        if(playerTurn == 1){
            fputc('O', fp);
        }
        fputc('\n', fp);
        printBoard(board, fp);


        //show them the state of the game
        //printBoard(board);
        //get a move from the user
        Move move = getValidMove(&board, playerTurn, &inputwindow, &cursortrackedWindow, board_row, board_col, fp);
        //place their move on the board
        placeMove(move, &board, &cursortrackedWindow, &inputwindow, fp);
        //change turn
        //playerTurn = (playerTurn + 1) % 2;
        playerTurn = playerTurn == Player1 ? Player2 : Player1;
    }

    for(int i = 0 ; i < inputwindow.inputCol; i++){
        fputc('_', fp);
    }

    if(playerTurn == 1){
        fputc('X', fp);
    }
    if(playerTurn == 0){
        fputc('O', fp);
    }
    fputc('\n', fp);

    for(int i = 0; i < board.numRows; i++){
        for(int j = 0; j < board.numCols; j++) {
            fputc(board.theBoard[i][j], fp);
        }
        fputc('\n', fp);
    }

    declareWinnerInTheWindow(&outputwindow, board, playerTurn, num_win, fp);
    getchar();
    endwin();
    cleanUpBoard(&board);
    fclose(fp);
    return 0;
}
