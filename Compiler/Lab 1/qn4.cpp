// Write a C/C++ program whether given input is Keyword or not (In case of C languge)
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    string keyword;
    char choice;
    do
    {
        cout << "Enter an Keyword: ";
        cin >> keyword;
        bool flag = false;
        for (int i = 0; i < 32; i++)
        {
            if (keyword == keywords[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout <<keyword<<" Is a valid Keyword" << endl;
        else
            cout <<keyword<<" Is not a valid Keyword" << endl;

        cout << "\nDo you want to continue? (Y,N): ";
        cin >> choice;

    } while (choice == 'Y'|| choice == 'y');

    return 0;
}