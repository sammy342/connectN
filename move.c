//
// Created by Sammy Veres on 11/14/17.
//

#include "move.h"
#include <stdio.h>
#include "inputValidation.h"

void getMove(char **board, const int num_rows, const int num_columns, char* prompt, char piece) {
    int move = getValidNum(prompt, 0, num_columns - 1);

    while (!isValidMove(board, num_rows, move))
    {
        move = getValidNum(prompt, 0, num_columns - 1);
    }

    for (int r = 0; r < num_rows ; ++r) {
        if(board[r][move] == '*'){
            board[r][move] = piece;
            return;
        }
    }

}

bool isValidMove(char **board, const int num_rows, int num) {

        for (int r = 0; r < num_rows ; ++r) {
            if(board[r][num] == '*'){
                return true;
            }
        }

    return false;

}


