#ifndef STACK_H
#define STACK_H
#include<iostream>

class Stack
{
public:
    virtual void push(int element)=0;
    virtual void pop()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
};

class ArrayStack : public Stack
{
private:
    int *data;
    int top;
    int maxStackSize;
   
public:
    ArrayStack()
    {
        maxStackSize=100;
        top=-1;
        data=new int[100];
    }

    virtual bool isEmpty()
    {
        return top < 0;
    }

    virtual bool isFull()
    {
        return top==maxStackSize-1;
    }    

    virtual void push(int element)
    {
        if(isFull()){
            std::cout<<"Stack Overflow."<<std::endl;
        }
        else
        {
            data[++top]=element;
        } 
    }
        
    virtual void pop()
    {
        if(!isEmpty()){
            std::cout<<data[top]<<std::endl;
            top--;
        }
        else
        {
            std::cout<<"Stack Underflow."<<std::endl;
        }
    }    
};

#endif