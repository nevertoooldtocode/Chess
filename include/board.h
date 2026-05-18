// include/board.h

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#define field_t int8_t
#define MAILBOXSIZE 120

typedef enum {White, Black} color_t;
typedef enum {Empty, Pawn, Knight, Bishop, Rook, Queen, King} piece_t;

typedef field_t *board_t;

board_t create_board();
void destroy_board(board_t b);
void init_oob(board_t b);
int place_piece(board_t b, color_t c, piece_t p, field_t f);

board_t create_board_from_fen(char* fen);

void print_mailbox(board_t b);
void print_board(board_t b);
void print_legal_moves();

#endif
