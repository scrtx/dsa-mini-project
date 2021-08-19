#ifndef Evaluation_H
#define Evaluation_H

#include"ArrayStack.h"
Stack*s=new ArrayStack;

bool isOperator(char op)
{
    if(op == '+' || op == '-' || op == '*' || op == '/'){
        return true;
    }
    else{
        return false;
    }
}

bool isOperand(char op)
{
    if(op >= '0' && op <= '9'){
        return true;
    }
    else{
        return false;
    }
}

int operate(int op1,int op2,char op)
{
    if(op == '+'){
        return op2 + op1;
    }
    else if(op == '-'){
        return op2 - op1;
    }
    else if(op == '*'){
        return op2 * op1;
    }
    else if(op == '/'){
        return op2 / op1;
    }
    else{
        return 0;
    }
}

void evaluate(char postfix[100])
{
    int i=0;
    int op1, op2, dummy;

    while (postfix[i]!='\0')
    {
        if(isOperand(postfix[i]))
        {
            dummy=(int)(postfix[i]);
            s->push(dummy);
        }
        else if(isOperator(postfix[i]))
        {
            op1=s->pop();
            op2=s->pop();
            s->push(operate(op1,op2,postfix[i]));
        }
        else
        {
            std::cout<<"Error"<<std::endl;
            break;
        }
        i++;
    }

    if(!s->isEmpty()){
        std::cout<<"Evaluated Result is : "<<s->pop()<<std::endl;
    }
}

#endif