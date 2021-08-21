#ifndef ArrayStack_H
#define ArrayStack_H
#include<iostream>

class Stack
{
public:
    virtual void push(int element)=0;
    virtual int pop()=0;
    virtual bool isEmpty()=0;
};

class ArrayStack : public Stack
{
private:
    int *data;
    int top;
    const int maxStackSize = 100;
   
public:
//Default Constructor of ArrayStack.
    ArrayStack()
    {
        top = -1;
        data=new int[maxStackSize]; //Initialize array for stack.
    }

//isEmpty() checks if stack is empty.
    virtual bool isEmpty()
    {
        return top < 0;
    }

//push() pushed data into the stack
    virtual void push(int element)
    {
        if(top == maxStackSize-1)
        {
            std::cout<<"Stack Overflow."<<std::endl;
        }
        else
        {
            data[++top]=element;
        }
    }

//pop() removes and returns the top element of stack.
    virtual int pop()
    {
        if(!isEmpty()){
            int x = data[top];
            top--;
            return x;
        }
        else
        {   
            std::cout<<"Stack Underflow."<<std::endl;
            return -1;
        }
    }    
};

#endif