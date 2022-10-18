#ifndef TESTS
//#define TESTS

#include <catch2/catch_test_macros.hpp>

#include "f_lab2_sequence.h"
#include "f_lab2_linkedlistsequence.h"
#include "f_lab2_arraysequence.h"

TEST_CASE( "we can get sequence value by index", "[sequence]" ) {
    int *items = new int[10];
    for (int i = 0; i < 10; i++) {
        items[i] = 2; 
    }
    LinkedListSequence<int> *l = new LinkedListSequence<int>(items, 10);
    REQUIRE( l->Get(1) == 2);
    REQUIRE( l->Get(5) == 2);
}

//#endif
