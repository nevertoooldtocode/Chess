// include/board.h

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

typedef int8_t board[120];

void print_board(board b);
void print_legal_moves();

#endif
