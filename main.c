
#include "board.h"
#include "inputValidation.h"
#include "win.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
    const char blankChar = '*';

    enoughArgs(argc);

    int numRows = atoi(argv[1]);
    int numCols = atoi(argv[2]);
    int numPiecesToWin = atoi(argv[3]);



    char **board = create_board(numRows, numCols, blankChar);
    gameLoop(board, numRows, numCols, blankChar, numPiecesToWin);


    return 0;
}


