//
// Created by Sammy Veres on 11/13/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "board.h"
//void freeBoard(char**board, )
void displayBoard(char **board, const int num_rows, const int num_cols) {
    for (int row = num_rows -1; row >= 0; row--) {
        printf("%d ", row);
        for (int col = 0; col < num_cols; ++col) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("  ");
    for(int col = 0; col < num_cols; col++){
        printf("%d ", col);
    }

}

char** create_board(int num_rows, int num_cols, char blank_space) {
    char** board = (char**) malloc(num_rows * sizeof(char*));
    for(int row = 0; row < num_rows; row++){
        board[row] = (char*) malloc(num_cols * sizeof(char));
        for (int col = 0; col < num_cols; ++col) {
            board[row][col] = blank_space;
        }
    }
    return board;
}
void cleanUp(char*** board, const int numRows, const int numCols){
    for (int row = 0; row < numRows ; ++row) {
        free((*board)[row]);
    }
    free(*board);
    *board = NULL;
}
