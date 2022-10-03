#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

#include "f_lab2_sequance.h"
//#include "f_lab2_dynamicarray.h"
#include "f_lab2_arraysequance.h"
//#include "f_lab2_linkedlist.h"
#include "f_lab2_linkedlistsequance.h"
#include "f_lab4_sort.h"

void parsing(int argc, char *argv[], bool &shell, int &size, int &step, string &output) {
    int i = 1;
    while (i < argc) {
        if ((string)argv[i] == "--shell") {
            shell = true;
        } else if ((string)argv[i] == "--size") {
            size = atoi(argv[i + 1]);
            i++;
        } else if ((string)argv[i] == "--step") {
            step = atoi(argv[i + 1]);
            i++;
        } else if ((string)argv[i] == "--output") {
            output = (string)argv[i + 1];
            i++;
        }
        i++;
    }
}

int comp(int left, int right) {
    return left - right;
}

int main(int argc, char *argv[]) {

    bool shell = false;
    int size = 100, step = 10;
    string output = "output";

    parsing(argc, argv, shell, size, step, output);

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
            LinkedListSequance<int> *a = new LinkedListSequance<int>(items, i, 1, i);
            clock_t start = clock();
            sort->sort(a, comp);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file << time << ",";
            delete a;
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
            ArraySequance<int> *b = new ArraySequance<int>(items, i, 1, i);
            clock_t start = clock();
            sort1->sort(b, comp);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            file1 << time << ",";
            delete b;
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
    
}
