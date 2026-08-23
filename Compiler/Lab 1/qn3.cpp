// Write a C/C++ program to simulate lexical analyser for validating operator(Arithmetic,Relational,Logical and Assignmenet)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arithmetic[] = {"+", "-", "*", "/", "%"};
	string relational[] = {"<", ">", "<=", ">=", "==", "!="};
	string logical[] = {"&&", "||", "!"};
	string assignment[] = {"=", "+=", "-=", "*=", "/=", "%="};

	string op;
	char choice;

	do
	{
		bool flag = false;
		cout << "Enter an operator: ";
		cin >> op;
		for (string item :arithmetic)
		{
			if (op == item)
			{
				cout << op << " is an Arithmetic Operator" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			for (string item : relational)
			{
				if (op == item)
				{
					cout << op << " is a Relational Operator" << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag)
		{
			for (string item : logical)
			{
				if (op == item)
				{
					cout << op << " is a Logical Operator" << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag)
		{
			for (string item :assignment)
			{
				if (op == item)
				{
					cout << op << " is an Assignment Operator" << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag)
		{
			cout << op << " is not a valid operator" << endl;
		}
		cout << "\nDo you want to continue? (Y,N): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	return 0;
}
