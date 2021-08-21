#include<iostream>
#include"Evaluation.h"

using namespace std;

int main()
{   
    string postfix; 

    cout<<"Please Enter expression with space between operands and operators."<<endl;
    cout<<"Enter a Postfix Expression : ";
    /*
    getline() takes input until delimiting character.
    cin doesn't read ' '.
    */
    getline(cin,postfix);

    cout<<"The evaluated Postfix results in : "<<evaluate(postfix);//calls evaluate()
    return 0;
}