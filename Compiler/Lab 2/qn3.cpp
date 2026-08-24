// Write a C/C++ program to recognize strings under a*, a*b+, and abb.
#include <iostream>
#include <string>
using namespace std;

enum states {q0, q1, q2, dead};

enum states delta(enum states state, char ch) {
    enum states curr_state = dead;

    switch (state) {
        case q0:
            if (ch == 'a')
                curr_state = q1;
            else if (ch == 'b')
                curr_state = q2;
            else
                curr_state = dead;
            break;

        case q1:
            if (ch == 'a')
                curr_state = q1;
            else if (ch == 'b')
                curr_state = q2;
            else
                curr_state = dead;
            break;

        case q2:
            if (ch == 'b')
                curr_state = q2;
            else
                curr_state = dead;
            break;

        case dead:
            curr_state = dead;
            break;
    }
    return curr_state;
}

int main() {
    string input;
    char choice;
    do{
        cout << "Enter the input string: ";
        getline(cin, input);

        enum states curr_state = q0;
        for (int i = 0; i < input.length(); i++) {
            curr_state = delta(curr_state, input[i]);
        }

        if (curr_state == q0 || curr_state == q1 || curr_state == q2) {
            cout << "The string \"" << input << "\" is accepted." << endl;
        } else {
            cout << "The string \"" << input << "\" is rejected." << endl;
        }
        cout << "Do you want to continue? (Y,N): ";
        cin >> choice;
        cin.ignore();
    }while(choice=='Y'||choice=='y');
    return 0;
}

