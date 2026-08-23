// Write a C/C++ program to identify whether input line is comment or not.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    char choice;
    do
    {
        
        cout << "Enter a line of code: ";
        getline(cin,str);
        int length = str.length();
        if (length >= 2)
        {
            if (str[0] == '/' && str[1] == '/')
            {
                cout << "The given string:\n"<<str<<"\nIs a Single Line Comment."<< endl;
            }
            else if (str[0] == '/' && str[1] == '*' && str[length - 2] == '*' && str[length - 1] == '/')
            {
                cout << "The given string:\n"<<str<<"\nIs a Multi Line Comment."<< endl;
            }
            else
            {
                cout << "The given string:\n"<<str<<"\nIs not Comment."<< endl;
            }
        }
        else
        {
            cout << "The given string:\n"<<str<<"\nIs not Comment."<< endl;
        }
        cout << "Do you want to continue? (Y,N): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'Y'|| choice == 'y');
    return 0;
}