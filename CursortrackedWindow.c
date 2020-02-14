#include "CursortrackedWindow.h"

CursorTrackedWindow makenewCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart){
    CursorTrackedWindow window;
    window.cursesWin = newwin(numRows,numCols,rowStart,colStart);
    window.cursorRow = rowStart;
    window.cursorCol = 0; //Set the cursor coordinate as(0,0)
    return window;
}

void fillWindow(CursorTrackedWindow* win, char fillChar){
    for(int i = 0; i < getmaxy(win->cursesWin); ++i){
        for(int j = 0; j < getmaxx(win->cursesWin); ++j){
            mvwaddch(win->cursesWin, i, j, fillChar);
        }

    }
    //wmove(win->cursesWin, 0, 0);//move the cursor to (0,0)//
}
