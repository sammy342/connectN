//
// Created by Sammy Veres on 11/13/17.
//

#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H
void displayBoard(char **board, const int num_rows, const int num_cols);
char** create_board(int num_rows, int num_cols, char blank_space);
void cleanUp(char ***board, const int numRows, const int numCols);

#endif //CONNECTN_BOARD_H
