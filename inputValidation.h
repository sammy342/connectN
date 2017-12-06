//
// Created by Sammy Veres on 11/14/17.
//

#ifndef CONNECTN_INPUTVALIDATION_H
#define CONNECTN_INPUTVALIDATION_H
#include <stdlib.h>
#include <stdbool.h>

int getValidNum(char* prompt, const int lower, const int upper);
void enoughArgs(int args);
bool isValidFormat(const int num_args_read, const int num_args_needed);
bool isInBounds(const int val, const int lower_bound, const int upper_bound);

#endif //CONNECTN_INPUTVALIDATION_H
