//
// Created by Sammy Veres on 11/14/17.
//

#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H

#include <stdbool.h>
void getMove(char **board, const int num_rows, const int num_columns, char* prompt, char piece);
bool isValidMove(char **board, const int num_rows, int num);



#endif //CONNECTN_MOVE_H
