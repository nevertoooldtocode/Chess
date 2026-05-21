// tests/test_board.c

#include <stdio.h>
#include <assert.h>
#include "../src/board.c"

void assert_algebraic_to_fieldindex() {
    assert(algebraic_to_fieldindex('a','1') == 21);
    assert(algebraic_to_fieldindex('h','8') == 98);
    assert(algebraic_to_fieldindex('c','4') == 53);
    assert(algebraic_to_fieldindex('g','2') == 37);
}

int main() {
    printf("Testing board.c\n");
    assert_algebraic_to_fieldindex();
}
