#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <gtest/gtest.h>

//#include "tests.h"
#include "f_lab2_sequence.h"
//#include "f_lab2_dynamicarray.h"
#include "f_lab2_arraysequence.h"
//#include "f_lab2_linkedlist.h"
#include "f_lab2_linkedlistsequence.h"
#include "f_lab4_sort.h"

int test_main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}


void parsing(int argc, char *argv[], bool &shell, int &size, int &step, string &output, bool &selection, bool &quick) {
    int i = 1;
    while (i < argc) {
        if ((string)argv[i] == "--shell") {
            shell = true;
        } else if ((string)argv[i] == "--selection") {
            selection = true;
        } else if ((string)argv[i] == "--size") {
            size = atoi(argv[i + 1]);
            i++;
        } else if ((string)argv[i] == "--step") {
            step = atoi(argv[i + 1]);
            i++;
        } else if ((string)argv[i] == "--output") {
            output = (string)argv[i + 1];
            i++;
        } else if ((string)argv[i] == "--quick") {
            quick = true;
        }
        i++;
    }
}

int comp(int left, int right) {
    return left - right;
}

int main(int argc, char *argv[]) {

    bool shell = false, selection = false, quick = false;
    int size = 100, step = 10;
    string output = "output";

    parsing(argc, argv, shell, size, step, output, selection, quick);

    int *items = new int[size];
    for (int i = 0; i < size; i++) {    
        items[i] = rand();
    }

    ofstream file;
    file.open(output + "1.csv", ios::out);

    if (shell) {
        ShellSort<int> *sort = new ShellSort<int>;
        file << "shell,";
        for (int i = step; i <= size; i += step) {
            cout << i << endl;

            LinkedListSequence<int> *a = new LinkedListSequence<int>(items, i);
            clock_t start = clock();
            Sequence<int> *c = (sort->sort(a, comp));
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file << time << ",";
            delete a;
            delete c;
        }
        file << '\n';
        delete sort;
    }
    if (selection) {
        SelectionSort<int> *sort = new SelectionSort<int>;
        file << "selection,";
        for (int i = step; i <= size; i += step) {
            cout << i << endl;
            LinkedListSequence<int> *a1 = new LinkedListSequence<int>(items, i);
            clock_t start = clock();
            Sequence<int> *c1 = (sort->sort(a1, comp));
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file << time << ",";
            delete a1;
            delete c1;
        }
        file << '\n';
        delete sort;
    }
    if (quick) {
        QuickSort<int> *sort = new QuickSort<int>;
        file << "quick,";
        for (int i = step; i <= size; i += step) {
            cout << i << endl;
            LinkedListSequence<int> *a4 = new LinkedListSequence<int>(items, i);
            clock_t start = clock();
            Sequence<int> *c4 = (sort->sort(a4, comp));
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file << time << ",";
            delete a4;
            delete c4;
        }
        file << '\n';
        delete sort;
    }



    file << "size,";
    for (int i = step; i <= size; i += step) {
        file << i << ',';
    }

    file.close();
    
    ofstream file1;
    file1.open(output + "2.csv", ios::out);

    if (shell) {
        ShellSort<int> *sort1 = new ShellSort<int>;
        file1 << "shell,";
        for (int i = step; i <= size; i += step) {
            cout << i << endl;
            ArraySequence<int> *b = new ArraySequence<int>(items, i);
            clock_t start = clock();
            Sequence<int> *c2 = sort1->sort(b, comp);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file1 << time << ",";
            delete b;
            delete c2;
        }
        file1 << '\n';
        delete sort1;
    }
    if (selection) {
        SelectionSort<int> *sort1 = new SelectionSort<int>;
        file1 << "selection,";
        for (int i = step; i <= size; i += step) {
            cout << i << endl;
            ArraySequence<int> *b1 = new ArraySequence<int>(items, i);
            clock_t start = clock();
            Sequence<int> *c3 = sort1->sort(b1, comp);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file1 << time << ",";
            delete b1;
            delete c3;
        }
        file1 << '\n';
        delete sort1;
    }    
    if (quick) {
        QuickSort<int> *sort1 = new QuickSort<int>;
        file1 << "quick,";
        for (int i = step; i <= size; i += step) {
            cout << i << endl;
            ArraySequence<int> *b5 = new ArraySequence<int>(items, i);
            clock_t start = clock();
            Sequence<int> *c5 = sort1->sort(b5, comp);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file1 << time << ",";
            delete b5;
            delete c5;
        }
        file1 << '\n';
        delete sort1;
    }



    file1 << "size,";
    for (int i = step; i <= size; i += step) {
        file1 << i << ',';
    }


    file1.close();

    string command = "python3 py.py " + output;
    system(command.c_str());//system work on char *;
                            
    string command1 = "python3 py1.py " + output;
    system(command1.c_str());//system work on char *;


    delete[] items;

    return test_main();

/*
    int *it = new int[10];
    for (int i  = 0; i < 10; i++) {
        cin >> it[i];
    }
    LinkedListSequence<int> *aaaa = new LinkedListSequence<int>(it, 10);
    SelectionSort<int> *aaa = new SelectionSort<int>;
    Sequence<int> *bbb = aaa->sort(aaaa, comp);
    for (int i = 0; i < 10; i++) {
        cout << bbb->Get(i) << endl;
    }
*/
}
