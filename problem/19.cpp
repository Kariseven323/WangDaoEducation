/**
 * @file 19.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#define MaxSize 5
using namespace std;
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;
void InitStack(SqStack &S)
{
    S.top = -1;
}
bool Push(SqStack &S,ElemType x)
{
    if(S.top==MaxSize-1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}
bool Pop(SqStack &S,ElemType &x)
{
    if(-1==S.top)
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}
typedef struct {
    ElemType data[MaxSize];
    int front;
    int rear;
} SqQueue;
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main()
{
    SqStack S;
    bool flag;
    ElemType m;
    InitStack(S);
    int i, num;
    for (int i = 0; i < 3;i++)
    {
        scanf("%d", &num);
        Push(S, num);
    }
    for (i = 0; i < 3;i++)
    {
        Pop(S, m);
        printf("%2d", m);
    }
    printf("\n");
    SqQueue Q;
    InitQueue(Q);
    for (i = 0; i < 5;i++)
    {
        scanf("%d", &num);
        flag = EnQueue(Q, num);
        if(false==flag)
        {
            printf("false\n");
        }
    }
    ElemType element;
    for (i = 0; i < 4;i++)
    {
        DeQueue(Q, element);
        printf("%2d", element);
    }
    printf("\n");
    return 0;
}