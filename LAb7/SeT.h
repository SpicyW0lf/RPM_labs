//
// Created by RaCHe on 08.02.2020.
//
#include <stdio.h>
#include <algorithm>
#ifndef LAB7_SET_H
#define LAB7_SET_H
using namespace std;

template <class Y>

class SeT {
private:
    int size = 0;
    Y* ptr = new Y[size];
    void Sort(Y* mas) {
        int step = size / 2;
        while (step > 0)//пока шаг не 0
        {
            for (int i = 0; i < (size - step); i++) {
                int j = i;
                while (j >= 0 && mas[j] > mas[j + step]) {
                    Y temp = mas[j];
                    mas[j] = mas[j + step];
                    mas[j + step] = temp;
                    j--;
                }
            }
            step = step / 2;
        }
    }
public:
    void Insert(Y al) {
        Y * tmp = new Y[size];
        for (int i=0; i< size; i++){
            tmp[i] = ptr[i];
        }
        delete[] ptr;
        ptr  = new Y[++size];

        for (int i=0; i< size-1; i++) ptr[i] = tmp[i];
        ptr[size-1] = al;
        Sort(ptr);
        delete[] tmp;
    }

    void Show() {
        if (size != 0) {
            cout << "{ ";
            for (int i = 0; i < size; i++) {
                cout << ptr[i];
                i < (size - 1) ? cout << ", " : cout << " }" << endl;
            }
        } else {
            cout << "Set is empty!";
        }
    }

    void Clear() {
        delete[] ptr;
        size = 0;
        ptr = new Y[size];
    }

    void Erase(Y ud) {
        Y* tmp = new Y[size];
        int ns = size;
        for (int i = 0; i < size; i++) {
            if (ptr[i] == ud) {
                size--;
                for (int j = i; j < size; j++) {
                    tmp[j] = ptr[j+1];
                }
                break;
            }
            tmp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = tmp;
        delete[] tmp;
    }
};



#endif //LAB7_SET_H
