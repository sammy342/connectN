//
// Created by Sammy Veres on 11/14/17.
//


#include <stdio.h>
#include <ctype.h>
#include "inputValidation.h"


int getValidNum(char* prompt, const int lower, const int upper) {
        int num;
        const int numArgsNeeded = 1;
        int numArgsRead;
        do{
            printf("%s", prompt);
            numArgsRead = scanf(" %d", &num);
        }while(!isValidFormat(numArgsRead, numArgsNeeded) ||
            !isInBounds(num, lower, upper));

        return num;
    }

void enoughArgs(int args){
    if(args > 4){
        printf("Too many arguments entered\nUsage connectn.out num_rows\n num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if(args < 4){
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns\n number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
}
bool isValidFormat(const int num_args_read, const int num_args_needed) {
    bool valid = num_args_read == num_args_needed;
    char c;

    //check that nothing came after
    do{
        scanf("%c", &c);
        if(!isspace(c)){
            valid = false;
        }
    }while(c != '\n');

    return valid;
}
bool isInBounds(const int val, const int lower_bound, const int upper_bound) {
    return val >= lower_bound && val <= upper_bound;
}


