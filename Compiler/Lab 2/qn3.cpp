// Write a C/C++ program to recognize strings under a*, a*b+, and abb.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    bool isAStar = true;
    bool isABPlus = true;
    bool isAbb = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a') {
            isAStar = false;
        }
    }

    if (s == "abb") {
        isAbb = true;
    }

    int i = 0;
    while (i < s.length() && s[i] == 'a') {
        i++;
    }

    if (i == s.length()) {
        isABPlus = false;
    }
    else {
        while (i < s.length() && s[i] == 'b') {
            i++;
        }
        if (i != s.length()) {
            isABPlus = false;
        }
    }

    if (isAStar) {
        cout << "Accepted under a*" << endl;
    }
    if (isABPlus) {
        cout << "Accepted under a*b+" << endl;
    }
    if (isAbb) {
        cout << "Accepted under abb" << endl;
    }
    if (!isAStar && !isABPlus && !isAbb) {
        cout << "String is not accepted" << endl;
    }
return 0;
}