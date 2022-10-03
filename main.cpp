#include <iostream>

#include "f_lab2_sequance.h"
#include "f_lab2_dynamicarray.h"
#include "f_lab2_arraysequance.h"
#include "f_lab2_linkedlist.h"
#include "f_lab2_linkedlistsequance.h"
#include "f_lab4_sort.h"

int comp(int left, int right) {
    return left - right;
}

int main() {
    int *item = new int[10];
    for (int i = 0; i < 10; i++) {
        cin >> item[i];
    }
    LinkedListSequance<int> *a = new LinkedListSequance<int>(item, 10, 1, 10);
    ShellSort<int> *sort = new ShellSort<int>;
    sort->sort(a, comp);
    for (int i = 0; i < 10; i++) {
        cout << a->Get(i) << endl;
    }
    delete a;
    delete sort;
    delete[] item;
    
}
