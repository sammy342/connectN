//
// Created by mfbut on 11/8/2017.
//

#ifndef TIC_TAC_TOE_WIN_H
#define TIC_TAC_TOE_WIN_H
#include <stdbool.h>

bool rowWin(char **board, int rows, int cols, char blank, const int piecesToWin);
bool colWin(char **board, int rows, int cols, char blank, const int piecesToWin);
bool rightDiagonalWin(char **board, int rows, int cols, int piecesToWin);
bool leftDiagonalWin(char **board, int rows, int cols, const char blank, const int piecesToWin);
bool boardFull(char **board, int rows, int cols, char blank, const int piecesToWin);
bool isGameOver(char **board, const int rows, const int cols, const char blank, int piecesToWin);
bool win(char **board, const int rows, const int cols, const char blank, const int piecesToWin);
bool tie(char **board, const int numRows, const int numCols, const char blank, const int piecesToWin);
void declareWinnerOrTie(char **board, int rows, int cols, const char blank, const int piecesToWin, int turn);
void gameLoop(char**board, int numRows, int numCols, char blankChar, int numPiecesToWin);



#endif //TIC_TAC_TOE_WIN_H