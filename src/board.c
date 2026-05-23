#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "board.h"

#define BOARDSIZE 64
#define OOBSIZE 56

/*
 * Board representation is a 120-cell Mailbox. The middle 64 cells are the board
 * The outer 56 cells indicate OOB, and are also used to store additional information
 * OOB is always negative (most significant bit 1)
 * Extra information in OOB cells (least significant 7 bits):
 * 	Cell 0: active color
 * 	Cell 1: castling
 * 	Cell 2: en passant target square
 * 	Cell 3: number of half moves since last pawn move or capture
 * 	Cell 4: number of full moves played
 *
 */

const field_t FIELDINDEX[BOARDSIZE] = {
    // The indices of the actual fields in a mailbox
    21, 22, 23, 24, 25, 26, 27, 28,
    31, 32, 33, 34, 35, 36, 37, 38,
    41, 42, 43, 44, 45, 46, 47, 48,
    51, 52, 53, 54, 55, 56, 57, 58,
    61, 62, 63, 64, 65, 66, 67, 68,
    71, 72, 73, 74, 75, 76, 77, 78,
    81, 82, 83, 84, 85, 86, 87, 88,
    91, 92, 93, 94, 95, 96, 97, 98
};

const field_t FENINDEX[BOARDSIZE] = {
    // The indices of the FEN fields in a mailbox
    91, 92, 93, 94, 95, 96, 97, 98,
    81, 82, 83, 84, 85, 86, 87, 88,
    71, 72, 73, 74, 75, 76, 77, 78,
    61, 62, 63, 64, 65, 66, 67, 68,
    51, 52, 53, 54, 55, 56, 57, 58,
    41, 42, 43, 44, 45, 46, 47, 48,
    31, 32, 33, 34, 35, 36, 37, 38,
    21, 22, 23, 24, 25, 26, 27, 28
};

const field_t OOBINDEX[OOBSIZE] = {
    // The indices of the out of bounds cells in a mailbox
    0, 1, 2, 3, 4, 5, 6, 7, 8 ,9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 29, 30, 39, 40, 49, 50, 59, 60, 69, 70, 79, 80, 89, 90, 99,
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119
};

const char PIECENAME[15] = {
    // The names of FEN pieces, the array index is our internal Piece enum
    ' ', 'P', 'N', 'B', 'R', 'Q', 'K', ' ',
    ' ', 'p', 'n', 'b', 'r', 'q', 'k'
};

static char find_piecename_index(char p) {
    //Finds Piece enum value for FEN piece name
    int i;
    for (i = 0; i < 15; i++) 
	if (p == PIECENAME[i])
	    return (char) i;
    return ' ';
}

static field_t algebraic_to_fieldindex(char file, char rank) {
    // Translates for instance a1 to 21, and h8 to 98
    if (file == '-') 
	return -1;
    return (field_t) (21 + (10 * (rank - 0x31) + (file - 0x61)));
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

color_t active_color(board_t b) {
    return b[0] & 1;
}

int place_piece(board_t b, color_t c, piece_t p, field_t f) {
    b[f] &= 0xf0; // Make empty
    b[f] |= (c << 3);
    b[f] |= p;
    return 0;
}

board_t create_board_from_fen(char* fen) {
    board_t b = create_board();
    int i = 0, f = 0, len = (int) strlen(fen);
    // First the board
    while (fen[i] != ' ' && i < len) {
	if (fen[i] == '/');
	else if (isdigit(fen[i])) 
	    f += (fen[i] - 48);
	else b[FENINDEX[f++]] = find_piecename_index(fen[i]);
	i++;
    }
    // Then the active color
    while (fen[i] == ' ') i++;
    if (fen[++i] != 'w')
	b[0] += 1;
    // Then Castling permissions

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
    printf("active color: %d\n", active_color(b));
}

void print_legal_moves() {
    printf("Legal moves!\n");
}
