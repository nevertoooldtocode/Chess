// src/main.c

#include <stdio.h>
#include "board.h"

int main() {
    int i;
    board startposition;
    for (i = 0; i < 120; i++) startposition[i] = i;

    print_board(startposition);
    print_legal_moves();
    return 0;
}

