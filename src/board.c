#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

const char PIECENAME[15] = {
    ' ', 'P', 'N', 'B', 'R', 'Q', 'K', ' ',
    ' ', 'p', 'n', 'b', 'r', 'q', 'k'};

static char find_piecename(char p) {
    int i;
    for (i = 0; i < 15; i++) 
	if (p == PIECENAME[i])
	    return (char) i;
    return ' ';
}

board_t create_board() {
    board_t b;
    b = (board_t) malloc(MAILBOXSIZE * sizeof(field_t));
    if (b == NULL) {
	printf("error in create_board\n");
	exit(1);
    }
    init_oob(b);
    return b;
}

void destroy_board(board_t b) {
    free(b);
}
void init_oob(board_t b) {
    int i;
    for (i = 0; i < OOBSIZE; i++)
	b[OOBINDEX[i]] = -128;
    for (i = 0; i < BOARDSIZE; i++)
	b[FIELDINDEX[i]] = 0;
}

int place_piece(board_t b, color_t c, piece_t p, field_t f) {
    b[f] &= 0xf0; // Make empty
    b[f] |= (c << 3);
    b[f] |= p;
    return 0;
}

board_t create_board_from_fen(char* fen) {
    board_t b = create_board();
    int i = 0, f = 63;
    while (fen[i] != ' ' && i < (int) strlen(fen)) {
	if (fen[i] == '/');
	else if (isdigit(fen[i])) 
	    f -= (fen[i] - 48);
	else b[FIELDINDEX[f--]] = find_piecename(fen[i]);
	i++;
    }
    printf("fen: %s\n", fen);
    return b;
}

void print_mailbox(board_t b) {
    printf("Print mailbox:\n");
    int r, c;
    for (r = 11; r >= 0; r--) {
	for (c = 0; c < 10; c++)
	    printf("%4d ", b[10*r + c]);
	printf("\n");
	}
    printf("\n");
}

void print_board(board_t b) {
    printf("Print board:\n");
    int r, c;
    for (r = 7; r >= 0; r--) {
	for (c = 0; c < 8; c++)
	    printf("%c ", PIECENAME[b[FIELDINDEX[8*r + c]]]);
	printf("\n");
    }
    printf("\n");
}

void print_legal_moves() {
    printf("Legal moves!\n");
}
