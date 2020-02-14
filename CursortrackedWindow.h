//
// Created by BMM Liu on 2/7/19.
//

#ifndef CONNECTN_CURSORTRACKEDWINDOW_H
#define CONNECTN_CURSORTRACKEDWINDOW_H

#include <ncurses.h>

typedef struct CursorTrackedWindor_Struct{
    WINDOW* cursesWin;
    int cursorRow, cursorCol;
}CursorTrackedWindow;

CursorTrackedWindow makenewCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart);
void fillWindow(CursorTrackedWindow* win, char fillChar);



#endif //CONNECTN_CURSORTRACKEDWINDOW_H
