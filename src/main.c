// src/main.c

#include <stdio.h>
#include "board.h"

int main() {
    /*
    board_t startposition = create_board();
    //init_oob(startposition);

    print_mailbox(startposition);
    //print_board(startposition);
    print_legal_moves();

    place_piece(startposition, White, King, 25);
    place_piece(startposition, Black, King, 95);
    print_mailbox(startposition);
    //print_board(startposition);
    destroy_board(startposition);
*/
    board_t startposition = create_board_from_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    print_mailbox(startposition);
    print_board(startposition);
    destroy_board(startposition);

    return 0;
}

