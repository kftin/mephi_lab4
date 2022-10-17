 #ifndef F_LAB4_SORT
#define F_LAB4_SORT

#include <iostream>
#include "f_lab2_sequance.h"

template <typename T>
class ISorter {
    public:
        virtual Sequance<T> *sort(Sequance<T> *seq, int (*comp)(T left, T right)) = 0;
        virtual ~ISorter() {};
};

template <typename T>
class ShellSort : public ISorter<T> {
    public:
    Sequance<T> *sort(Sequance<T> *seq, int (*comp)(T left, T right)) override {
        Sequance<T> *res = seq->Copy();
        int length = res->GetLength();
        int step = length / 2;
        while (step) {
            for (int i = 0; i < length; i++) {
                for (int j = i; j + step < length; j += step) {
                    int f = comp(res->Get(j), res->Get(j + step));
                    if (f > 0) {
                        T tmp = res->Get(j);
                        res->Set(j, res->Get(j + step));
                        res->Set(j + step, tmp);
                    }
                }
            }
            step /= 2;
        }
        return res;
    }
};

template <typename T>
class SelectionSort : public ISorter<T> {
    public:
    Sequance<T> *sort(Sequance<T> *seq, int (*comp)(T left, T right)) override {
        Sequance<T> *res = seq->Copy();
        for (int i = 0; i < res->GetLength() - 1; ++i) {
            int min_i = i;
            for (int j = i + 1; j < res->GetLength(); ++j) {
                if (comp(res->Get(min_i), res->Get(j) > 0)) {
                    min_i = j;
                }
            }
            if (i != min_i) {
                T tmp = res->Get(i);
                res->Set(i, res->Get(min_i));
                res->Set(min_i, tmp);
            }
        }
        return res;
    }
};

#endif
