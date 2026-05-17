#include <stdio.h>
#include "board.h"

#define BOARDSIZE 64
#define OOBSIZE 56

const field_t FIELDINDEX[BOARDSIZE] = {
    21, 22, 23, 24, 25, 26, 27, 28,
    31, 32, 33, 34, 35, 36, 37, 38,
    41, 42, 43, 44, 45, 46, 47, 48,
    51, 52, 53, 54, 55, 56, 57, 58,
    61, 62, 63, 64, 65, 66, 67, 68,
    71, 72, 73, 74, 75, 76, 77, 78,
    81, 82, 83, 84, 85, 86, 87, 88,
    91, 92, 93, 94, 95, 96, 97, 98};

const field_t OOBINDEX[OOBSIZE] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8 ,9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 29, 30, 39, 40, 49, 50, 59, 60, 69, 70, 79, 80, 89, 90, 99,
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119};

void init_oob(board_t b) {
    int i;
    for (i = 0; i < OOBSIZE; i++)
	b[OOBINDEX[i]] = -1;
}

int place_piece(board_t b, color_t c, piece_t p, field_t f) {
    return 0;
}

void print_mailbox(board_t b) {
    printf("Print mailbox:\n");
    int r, c;
    for (r = 11; r >= 0; r--) {
	for (c = 0; c < 10; c++)
	    printf("%d, ", b[10*r + c]);
	printf("\n");
	}
    printf("\n");
}

void print_board(board_t b) {
    printf("Print board:\n");
    int r, c;
    for (r = 7; r >= 0; r--) {
	for (c = 0; c < 8; c++)
	    printf("%d, ", b[FIELDINDEX[8*r + c]]);
	printf("\n");
    }
    printf("\n");
}

void print_legal_moves() {
    printf("Legal moves!\n");
}
