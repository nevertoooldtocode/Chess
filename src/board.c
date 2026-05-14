#include <stdio.h>
#include "board.h"

enum color {White, Black};
enum piece {Empty, Pawn, Knight, Bishop, Rook, Queen, King};

#define BOARDSIZE 64

const field_t FIELDINDEX[BOARDSIZE] = {
    21, 22, 23, 24, 25, 26, 27, 28,
    31, 32, 33, 34, 35, 36, 37, 38,
    41, 42, 43, 44, 45, 46, 47, 48,
    51, 52, 53, 54, 55, 56, 57, 58,
    61, 62, 63, 64, 65, 66, 67, 68,
    71, 72, 73, 74, 75, 76, 77, 78,
    81, 82, 83, 84, 85, 86, 87, 88,
    91, 92, 93, 94, 95, 96, 97, 98};

void print_mailbox(board b) {
    printf("Print mailbox: ");
    int i;
    for (i = 0; i < MAILBOXSIZE; i++) 
	printf("%d, ", b[i]);
    printf("\n");
}

void print_board(board b) {
    printf("Print board: ");
    int i;
    for (i = 0; i < BOARDSIZE; i++) 
	printf("%d, ", FIELDINDEX[b[i]]);
    printf("\n");
}

void print_legal_moves() {
    printf("Legal moves!\n");
}
