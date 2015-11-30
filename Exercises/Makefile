#
# Makefile for tetris
#
#

tetris: tetris.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o tetris tetris.c -lcs -lm

clean:
	rm -f *.o core tetris
