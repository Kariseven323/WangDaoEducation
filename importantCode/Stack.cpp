/**
 * @file Stack.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#define MaxSize 100
using namespace std;
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;
void InitStack(SqStack &s)
{
    s.top = -1;
}
bool StackEmpty(SqStack &s)
{
    if(s.top==-1)
        return true;
        else
            return false;
}
bool Push(SqStack &s,ElemType e)
{
    if(s.top==MaxSize-1)
    {
        return false;
    }
    s.data[++s.top];
    return true;
}
bool Pop(SqStack &s,ElemType &e)
{
    if(-1==s.top)
        return false;
    e = s.data[s.top--];
    return true;
}
bool GetTop(SqStack &s,ElemType &e)
{
    if(-1==s.top)
    {
        return false;
    }
    e = s.data[s.top];
    return true;
}