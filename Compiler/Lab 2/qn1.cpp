// Write a C/C++ program to implement DFA for accepting all string end with 00 over an alphabet {0,1}.
#include<iostream>
using namespace std;
enum states {q0,q1,qf};
enum states delta(enum states state,char ch){
    enum states curr_state;
    switch (state){
        case q0: if(ch=='0'){
                    curr_state=q1;
                }
                else{
                    curr_state=q0;
                }
                break;
        case q1: if(ch=='0'){
                    curr_state=qf;
                }
                else{
                    curr_state=q0;
                }
                break;
        case qf: if(ch=='0'){
                    curr_state=qf;
                }
                else{
                    curr_state=q0;
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
    cout<<"Enter the input string:";
    cin>>input;
    ch=input[i];
    enum states curr_state=q0;
    while(ch!='\0'){
        curr_state=delta(curr_state,ch);
        ch=input[++i];
    }
    if(curr_state==qf)
    {
        cout << "The string \"" << input << "\" is accepted." << endl;
    }
    else
    {
        cout << "The string \"" << input << "\" is rejected." << endl;
    }
    return 0;
}

