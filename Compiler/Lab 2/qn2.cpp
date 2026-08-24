// Write a C/C++ program to implement DFA for accepting even no of 0's and even no of 1's.
#include<iostream>
using namespace std;
enum states {q0,q1,q2,q3};
enum states delta(enum states state,char ch){
    enum states curr_state;
    switch (state){
        case q0: if(ch=='0'){
                    curr_state=q1;
                }
                else{
                    curr_state=q2;
                }
                break;
        case q1: if(ch=='0'){
                    curr_state=q0;
                }
                else{
                    curr_state=q3;
                }
                break;
        case q2: if(ch=='0'){
                    curr_state=q3;
                }
                else{
                    curr_state=q0;
                }
                break;
        case q3: if(ch=='0'){
                    curr_state=q2;
                }
                else{
                    curr_state=q1;
                }
                break;
    }
    return curr_state;
}
int main()
{
    string input;
    char ch;
    int i=0;
    char choice;
    do{
        cout<<"Enter the input string:";
        cin>>input;
        ch=input[i];
        enum states curr_state=q0;
        while(ch!='\0'){
            curr_state=delta(curr_state,ch);
            ch=input[++i];
        }
        if(curr_state==q0)
        {
            cout << "The string \"" << input << "\" is accepted." << endl;
        }
        else
        {
            cout << "The string \"" << input << "\" is rejected." << endl;
        }
        cout << "Do you want to continue? (Y,N): ";
        cin >> choice;
        cin.ignore();

    }while(choice=='Y'||choice=='y');
    
    return 0;
}

