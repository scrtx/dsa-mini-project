#include<iostream>
#include"Evaluation.h"

using namespace std;

int main()
{   
    char postfix[100];
    cout<<"Enter a Postfix Expression : "<<endl;
    cin>>postfix;
    cout<<"Given Postfix Expression is : "<<postfix<<endl;
    evaluate(postfix);
    return 0;
}