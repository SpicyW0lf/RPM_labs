#include <iostream>
#include <stdio.h>
#include <string.h>
#include "SeT.h"

using namespace std;

int main() {
    string s;
    int a;
    SeT<string> con;
    while (true) {
        cout << "1) Enter" << endl;
        cout << "2) Show" << endl;
        cout << "3) Clear" << endl;
        cout << "4) Erase" << endl;
        cin >> a;
        switch (a) {
            case 1:
                cin >> s;
                con.Insert(s);
                break;
            case 2:
                con.Show();
                break;
            case 3:
                con.Clear();
                break;
            case 4:
                cin >> s;
                con.Erase(s);
                break;
        }
    }

    return 0;
}
