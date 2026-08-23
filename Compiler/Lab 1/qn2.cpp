// Write a C/C++ program whether given input is vlaid identifier or not.
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
    string identifier;
    char choice;
    do
    {
        cout << "Enter an identifier: ";
        cin >> identifier;
        int length=identifier.length();
        bool flag = false,flag1=false;
        if (identifier[0] == '_' || isalpha(identifier[0]))
        {
            for (int i = 1; i < length; i++)
            {
                if (!(isalnum(identifier[i]) || identifier[i] == '_'))
                {
                    flag = true;
                    break;
                }
            }

            for (int i = 0; i < 32; i++)
            {
                if (identifier == keywords[i])
                {
                    flag1= true;
                    break;
                }
            }
            if (flag1)
                cout <<identifier<<" Is not a valid identifier,It's a keyword" << endl;
            else if (flag)
                cout <<identifier<<" Is not a valid identifier" << endl;
            else
                cout <<identifier<<" Is a valid identifier" << endl;
        }
        else
        {
            cout <<identifier<<" Is not a valid identifier" << endl;
        }
        cout << "\nDo you want to continue? (Y,N): ";
        cin >> choice;

    } while (choice == 'Y'|| choice == 'y');

    return 0;
}