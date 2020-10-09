#include <iostream>
#include "DB.h"
using namespace std;
#define APPART(x) { \
int floor, size, square;\
string area;\
cout << "Enter your area: ";\
cin >> area;\
cout << endl << "Enter your floor: ";\
cin >> floor;\
cout << endl << "Enter your size: ";\
cin >> size;\
cout << endl << "Enter your square: ";\
cin >> square;\
file.x({ Area(area),Floor(floor),Size(size),Square(square) });\
} \

int main() {
    File file;
    while (cin) {
        string command;
        cin >> command;

        if (command == "ADD") {
            APPART(AddApart);
        }
        else if (command == "FIND") {
            APPART(FindApart);
        }
        else if (command == "SHOW") {
            file.ShowAparts();
        }
    }
    cin.get();
}

