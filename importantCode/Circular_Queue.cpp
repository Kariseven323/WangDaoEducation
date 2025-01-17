/**
 * @file Circular_Queue.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#define MaxSize 5
using namespace std;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;
void InitQueue(SqQueue &q)
{
    q.rear = q.front = 0;
}
bool isEmpty(SqQueue &q)
{
    if(q.rear==q.front)
    {
        return true;
    }else
    {
        return false;
    }
}
bool EnQueue(SqQueue &q,ElemType e)
{
    if((q.rear+1)%MaxSize==q.front)
    {
        return false;
    }
    q.data[q.rear] = e;
    q.rear = (q.rear + 1) % MaxSize;
    return true;
}
bool DeQueue(SqQueue &q,ElemType &e)
{
    if(q.rear==q.front)
        return false;
    e = q.data[q.front];
    q.front = (q.front + 1) % MaxSize;
    return true;
}
