connectn.out: main.o board.o move.o win.o inputValidation.o
	gcc -g -Wall -Werror -o connectn.out main.o board.o move.o win.o inputValidation.o

main.o: main.c board.h inputValidation.h win.h
	gcc -g -Wall -Werror -c main.c

win.o: win.c board.h move.h win.h
	gcc -g -Wall -Werror -c win.c

move.o: move.c inputValidation.h move.h
	gcc -g -Wall -Werror -c move.c

inputValidation.o: inputValidation.c inputValidation.h
	gcc -g -Wall -Werror -c inputValidation.c

board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c

