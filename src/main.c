// src/main.c

#include <stdio.h>
#include "board.h"

int main() {
    //int i;
    board_t startposition = {0};
    //for (i = 0; i < 120; i++) startposition[i] = i;
    init_oob(startposition);

    print_mailbox(startposition);
    print_board(startposition);
    print_legal_moves();
    return 0;
}

