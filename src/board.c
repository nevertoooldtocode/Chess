#include <stdio.h>
#include "board.h"

void print_board(board b) {
    printf("Print board: ");
    int i;
    for (i = 0; i < 120; i++) printf("%d, ", b[i]);
}

void print_legal_moves() {
    printf("Legal moves!\n");
}
