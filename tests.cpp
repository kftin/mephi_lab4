#include <gtest/gtest.h>
#include "f_lab2_linkedlistsequence.h"
#include "f_lab2_arraysequence.h"
#include <exception>

TEST(ArraySequenceTest, ArrayLength) {
    int items[] = {1, 2, 3};
    ArraySequence<int> seq(items, 3);
    ASSERT_EQ(seq.GetLength(), 3);
}

TEST(ArraySequenceTest, ArrayInitialization) {
    int items[] = {0, 1, 2};
    ArraySequence<int> seq(items, 3);
    for (int i = 0; i < 3; i++) {
        ASSERT_EQ(seq.Get(i), i);
    }
}

TEST(ArraySequenceTest, ArrayAppend) {
    int items[] = {1, 1};
    ArraySequence<int> seq(items, 2);
    seq.Append(5);
    ASSERT_EQ(seq.Get(2), 5);
}

TEST(ArraySequenceTest, ArrayPrepend) {
    int items[] = {1, 1};
    ArraySequence<int> seq(items, 2);
    seq.Prepend(5);
    ASSERT_EQ(seq.Get(0), 5);
}

TEST(ArraySequenceTest, ArrayInsertAt) {
    int items[] = {1, 1};
    ArraySequence<int> seq(items, 2);
    seq.InsertAt(5, 1);
    ASSERT_EQ(seq.Get(1), 5);
}
/*
TEST(ArraySequenceTest, ArrayConcat) {
    int items[] = {0, 1, 2};
    int items1[] = {3, 4, 5};
    ArraySequence<int> *seq = new ArraySequence<int>(items, 3);
    ArraySequence<int> *seq1 = new ArraySequence<int>(items1, 3);
    ArraySequence<int> *res = (ArraySequence<int> *)seq->Concat(seq);
    for (int i = 0; i < res->GetLength(); i++) {
        ASSERT_EQ(res->Get(i), i);
    }
    delete seq;
    delete seq1;
}*/

