#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#define SIZE_MAX 128

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}


int main() {

    vector v = createVector(0);
    test();

    return 0;
}