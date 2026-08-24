// write a program to implement design of lexical analyser to recognize token (identifier, keyword, operator, constant and special symbol) etc.
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
int main() {
    cout << "Enter source code line by line." << endl;
    cout << "Press Enter on a blank line to finish." << endl;

    ofstream outFile("input.txt");
    if (!outFile) {
        cout << "Unable to create input.txt" << endl;
        return 0;
    }

    string line;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        outFile << line << endl;
    }
    outFile.close();

    ifstream file("input.txt");
    if (!file) {
        cout << "Unable to open input.txt for reading." << endl;
        return 0;
    }

    string sourceCode;
    while (getline(file, line)) {
        sourceCode += line + "\n";
    }
    file.close();

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
    int i = 0;
    while (i < sourceCode.length()) {
        ch = sourceCode[i];

        if (isalpha(ch)) {
            word = "";
            while (i < sourceCode.length() && isalpha(sourceCode[i])) {
                word += sourceCode[i];
                i++;
            }

            bool found = false;
            for (int j = 0; j < 10; j++) {
                if (word == key[j]) {
                    found = true;
                    break;
                }
            }

            if (found) {
                bool alreadyExists = false;
                for (int j = 0; j < k; j++) {
                    if (keywords[j] == word) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists)
                    keywords[k++] = word;
            } else {
                bool alreadyExists = false;
                for (int j = 0; j < id; j++) {
                    if (identifiers[j] == word) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists)
                    identifiers[id++] = word;
            }
        }
        else if (isdigit(ch)) {
            word = "";
            while (i < sourceCode.length() && isdigit(sourceCode[i])) {
                word += sourceCode[i];
                i++;
            }

            bool alreadyExists = false;
            for (int j = 0; j < c; j++) {
                if (constants[j] == word) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
                constants[c++] = word;
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' ||
                 ch == '=' || ch == '<' ||
                 ch == '>') {

            string opSymbol(1, ch);
            bool alreadyExists = false;
            for (int j = 0; j < op; j++) {
                if (operators[j] == opSymbol) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
                operators[op++] = opSymbol;
            i++;
        }
        else if (ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' ||
                 ch == ';' || ch == ',' ||
                 ch == '[' || ch == ']') {

            string sym(1, ch);
            bool alreadyExists = false;
            for (int j = 0; j < sp; j++) {
                if (specialSymbols[j] == sym) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
                specialSymbols[sp++] = sym;
            i++;
        }
        else {
            i++;
        }
    }
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