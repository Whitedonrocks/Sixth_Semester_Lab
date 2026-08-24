// write a program to implement design of lexical analyser to recognize token (identifier, keyword, operator, constant and special symbol) etc.
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
int main() {

    ifstream file("input.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return 0;
    }
    // Arrays to store tokens
    string keywords[100];
    string identifiers[100];
    string constants[100];
    string operators[100];
    string specialSymbols[100];
    int k = 0, id = 0, c = 0, op = 0, sp = 0;
    // List of keywords
    string key[] = {
        "int", "float", "char", "double",
        "if", "else", "for", "while",
        "return", "void"
    };
    char ch;
    string word;
    while (file.get(ch)) {
        // If character is a letter, make a word
        if (isalpha(ch)) {
            word = "";
            while (isalpha(ch)) {
                word = word + ch;
                if (!file.get(ch))
                    break;
            }
            // Check whether word is keyword
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (word == key[i]) {
                    found = true;
                    break;
                }
            }
            if (found)
                keywords[k++] = word;
            else {
                bool alreadyExists = false;
                for (int i = 0; i < id; i++) {
                    if (identifiers[i] == word) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists)
                    identifiers[id++] = word;
            }

            // Put character back
            if (file)
                file.unget();
        }
        // If character is a number
        else if (isdigit(ch)) {
            word = "";

            while (isdigit(ch)) {
                word = word + ch;

                if (!file.get(ch))
                    break;
            }

            constants[c++] = word;

            if (file)
                file.unget();
        }
        // Operators
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' ||
                 ch == '=' || ch == '<' ||
                 ch == '>') {

            operators[op++] = ch;
        }
        // Special symbols
        else if (ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' ||
                 ch == ';' || ch == ',' ||
                 ch == '[' || ch == ']') {

            specialSymbols[sp++] = ch;
        }
    }
    file.close();
    // Display results
    cout << "\nKeywords:\n";
    for (int i = 0; i < k; i++)
        cout << keywords[i] << " ";
    cout << "\n\nIdentifiers:\n";
    for (int i = 0; i < id; i++)
        cout << identifiers[i] << " ";
    cout << "\n\nConstants:\n";
    for (int i = 0; i < c; i++)
        cout << constants[i] << " ";
    cout << "\n\nOperators:\n";
    for (int i = 0; i < op; i++)
        cout << operators[i] << " ";
    cout << "\n\nSpecial Symbols:\n";
    for (int i = 0; i < sp; i++)
        cout << specialSymbols[i] << " ";
    cout << endl;
    return 0;
}