//
// Created by Sammy Veres on 11/14/17.
//

#include "win.h"
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "move.h"
bool rowWin(char **board, int rows, int cols, char blank, const int piecesToWin) {

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 'X') {
                int countX = 0;
                for (int i = r; i < rows; ++i) {

                    if (board[i][c] == 'X') {
                        countX++;
                    } else {
                        break;
                    }
                }
                if (countX == piecesToWin) {
                    return true;
                }
            }
            if (board[r][c] == 'O') {
                int countR = 0;
                for (int i = r; i < rows; ++i) {
                    if (board[i][c] == 'O') {
                        countR++;
                    } else {
                        break;
                    }
                }

                if (countR == piecesToWin) {
                    return true;
                }
            }
        }
    }
    return false;

}

bool colWin(char **board, int rows, int cols, char blank, const int piecesToWin) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            if (r == rows - 1) {
                continue;
            }
            if (board[r][c] == 'X') {
                int countX = 0;
                for (int i = c; i < cols; ++i) {
                    if (board[r][i] == 'X') {
                        countX++;
                    } else {
                        break;
                    }
                }
                if (countX == piecesToWin) {
                    return true;
                }
            } else {
                int countR = 0;
                for (int i = r; i < rows; ++i) {
                    if (countR == piecesToWin) {
                        return true;
                    }
                    if (board[r][i] == 'O') {
                        countR++;
                        continue;
                    } else {
                        break;
                    }

                }
                if (countR == piecesToWin) {
                    return true;
                }
            }
        }
    }
    return false;

}

bool rightDiagonalWin(char **board, int rows, int cols, int piecesToWin) {

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            if (r == 0) {
                continue;
            }

            if (board[r][c] == 'X') {
                int diagCountX = 0;
                int max = (r > cols - c) ? cols - c : r;
                for (int i = 0; i <= max; ++i) {

                    if (board[r - i][c + i] == 'X') {
                        diagCountX++;
                    } else {
                        break;
                    }

                }

                if (diagCountX == piecesToWin) {
                    return true;
                }

            }
            if (board[r][c] == 'O') {
                int diagCountO = 0;
                int max = (r > cols - c) ? cols - c : r;
                for (int i = 0; i <= max; ++i) {

                    if (board[r - i][c + i] == 'O') {
                        diagCountO++;

                    } else {
                        break;
                    }

                }
                if (diagCountO == piecesToWin) {
                    return true;
                }

            }

        }
    }
    return false;
}

bool leftDiagonalWin(char **board, int rows, int cols, const char blank, const int piecesToWin) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            if (r == rows - 1) {
                continue;
            }

            if (board[r][c] == 'X') {
                int diagCountO = 0;
                int max = (rows - r > cols - c) ? cols - c : rows - r;
                for (int i = 0; i < max; ++i) {
                    if (board[r + i][c + i] == 'X') {
                        diagCountO++;
                    } else {
                        break;
                    }
                }
                if (diagCountO == piecesToWin) {
                    return true;
                }
            }
            if (board[r][c] == 'O') {
                int diagCountO = 0;
                int max = (rows - r > cols - c) ? cols - c : rows - r;
                for (int i = 0; i < max; ++i) {
                    if (board[r + i][c + i] == 'O') {
                        diagCountO++;
                    } else {
                        break;
                    }
                }
                if (diagCountO == piecesToWin) {
                    return true;
                }
            }

        }
    }
    return false;
}

bool boardFull(char **board, int rows, int cols, char blank, const int piecesToWin) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == '*') {
                return false;
            }
        }
    }
    return true;
}

bool isGameOver(char **board, const int rows, const int cols, const char blank, int piecesToWin) {
    return win(board, rows, cols, blank, piecesToWin) || tie(board, rows, cols, blank, piecesToWin);

}
bool win(char **board, const int rows, const int cols, const char blank, const int piecesToWin) {
    return rowWin(board, rows, cols, blank, piecesToWin)
        || colWin(board, rows, cols, blank, piecesToWin)
        || leftDiagonalWin(board, rows, cols, blank, piecesToWin)
        || rightDiagonalWin(board, rows, cols, piecesToWin);

}
bool tie(char **board, const int numRows, const int numCols, const char blank, const int piecesToWin) {
    return boardFull(board, numRows, numCols, blank, piecesToWin);
}

void declareWinnerOrTie(char **board, int rows, int cols, const char blank, const int piecesToWin, int turn) {
    if (win(board, rows, cols, blank, piecesToWin)) {
        printf("\nPlayer %d Won!", turn == 0 ? 2 : 1);
    } else {
        printf("Tie game!");
    }
    exit(0);
}

void gameLoop(char **board, int numRows, int numCols, char blankChar, int numPiecesToWin) {
    int playerTurn = 0;
    const char pieces[] = "XO";

    char *prompt = (char*) malloc(100 * sizeof(char));
    sprintf(prompt, "Enter a column between 0 and %d to play in: ", numCols - 1);

    do {
        displayBoard(board, numRows, numCols);
        getMove(board, numRows, numCols, prompt, pieces[playerTurn]);
        playerTurn = (playerTurn == 0) ? 1 : 0;
    } while (!isGameOver(board, numRows, numCols, blankChar, numPiecesToWin));

    displayBoard(board, numRows, numCols);
    declareWinnerOrTie(board, numRows, numCols, blankChar, numPiecesToWin, playerTurn);
    cleanUp(&board, numRows, numCols);
    free(prompt);
}



