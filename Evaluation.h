#ifndef Evaluation_H
#define Evaluation_H

#include<string>
#include"ArrayStack.h"
ArrayStack s;

//Function checks if character is operator.
bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Fuction checks if input is operand.
bool isOperand(char op)
{
    if (op >= '0' && op <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Function operates op1 and op2 with operator op.
int operate(int op1, int op2, char op)
{   
    if(op == '+')
    {
        return op2 + op1;
    }

    else if(op == '-')
    {
        return op2 - op1;
    }

    else if(op == '*')
    {
        return op2 * op1;
    }

    else if(op == '/')
    {
        return op2 / op1;
    }

    else
    {
        std::cout<<"Error"<<std::endl;
        return -1;
    }
}

//Function to Evaluate given Postfix expression.
int evaluate(std::string postfix)
{
    int op1=0, op2=0;
    
    for (int i=0 ; i < postfix.length() ; i++)
    {
        if(postfix[i] == ' ')
        {
            //Skips spaces in Postfix expression.
            continue;
        }
        else if(isOperator(postfix[i]))
        {   
            //pop Two operands which are to be operated.
            op1 = s.pop();
            op2 = s.pop();
            
            //Pushes the Operated result into Stack
            s.push(operate(op1, op2, postfix[i]));
        }
        else if(isOperand(postfix[i]))
        {
			int num = 0; 
            //Loop is used to extract complete number for numbers with multiple digits.
			while(i < postfix.length() && isOperand(postfix[i]))
            {
				num = 10 * num + (postfix[i] - '0'); 
                /*The place value of num is increased and
                (postfix[i] - '0') give number in postfix[i]*/
				i++;
			}
            s.push(num); // pushes the num into stack.
            --i; 
            /*i should be decreased since it went pass the number after while loop.*/ 
        }
        else
        {
            //Gives error message when input is not ' ', number or operator.
            std::cout<<"Error, Invalid Input"<<std::endl;
            break;
        }
    }
    /*
    Returns the final solution.
    It was pushed into stack after final operation was done.
    */
    return s.pop();
}

#endif