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

#endif
