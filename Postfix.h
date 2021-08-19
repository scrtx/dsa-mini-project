#ifndef POSTFIX_H
#define POSTFIX_H

bool isOperator(char op)
{
    if(op=="+"||op=="-"||op=="*"||op=="/"){
        return true;
    }
    else{
        return false;
    }
}

bool isOperand(char op)
{
    if(op >= '0')
}

int operate(int op1,int op2,char op)
{
    if(op=="+"){
        return op2 + op1;
    }
    else if(op=="-"){
        return op2 - op1;
    }
    else if(op=="*"){
        return op2 * op1;
    }
    else if(op=="/"){
        return op2 / op1;
    }
    else{
        return 0;
    }
}

void evaluate(char postfix[100])
{
    int i=0;
    while (postfix[i]!='\0')
    {
        if(!isOperator()){}
        i++;
    }
    
}

#endif