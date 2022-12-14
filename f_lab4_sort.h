 #ifndef F_LAB4_SORT
#define F_LAB4_SORT

#include <iostream>
#include "f_lab2_sequence.h"
#include <time.h>

template <typename T>
class ISorter {
    public:
        virtual Sequence<T> *sort(Sequence<T> *seq, int (*comp)(T left, T right)) = 0;
        virtual ~ISorter() {};
};

template <typename T>
class ShellSort : public ISorter<T> {
    public:
    Sequence<T> *sort(Sequence<T> *seq, int (*comp)(T left, T right)) override {
        Sequence<T> *res = seq->Copy();
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

template<typename T>
class QuickSort : public ISorter<T> {
private:
    void Qsorter(Sequence<T> * seq, int low, int high, int (*comp)(T left, T rigth)) {
        int i = low;
        int j = high;
        T buf = seq->Get((i + j) / 2);

        while (i <= j) {
            while (comp(seq->Get(i), buf) < 0) ++i;

            while (comp(seq->Get(j), buf) > 0) --j;
            if (i <= j) {

                T tmp = seq->Get(i);
                seq->Set(i, seq->Get(j));
                seq->Set(j, tmp);

                ++i;
                --j;
            }
        }
        if (j > low) Qsorter(seq, low, j, comp);
        if (i < high) Qsorter(seq, i, high, comp);
    }

public:

    Sequence<T> *sort(Sequence<T> *seq, int (*comp)(T left, T rigth)) override {
        Sequence<T> *res = seq->Copy();
        clock_t start = clock();
        Qsorter(res, 0, res->GetLength() - 1, comp);
        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << time << endl;
        return res;
    }
};



template <typename T>
class SelectionSort : public ISorter<T> {
    public:
    Sequence<T> *sort(Sequence<T> *seq, int (*comp)(T left, T right)) override {
        Sequence<T> *res = seq->Copy();
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
