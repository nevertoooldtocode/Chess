// include/board.h

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#define field_t int8_t
#define MAILBOXSIZE 120

typedef field_t board[MAILBOXSIZE];

void print_mailbox(board b);
void print_board(board b);
void print_legal_moves();

#endif
