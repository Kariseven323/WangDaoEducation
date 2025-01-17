/**
 * @file Queue.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} LinkNode,*LinkList;
typedef struct{
    LinkNode *front, *rear;
} LinkQueue;
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = (LinkList)malloc(sizeof(LinkNode));
    q.front->next = NULL;
}
bool isEmpty(LinkQueue q)
{
    if(q.front==q.rear)
    {
        return true;
    }else{
        return false;
    }
}
void EnQueue(LinkQueue &q,ElemType e)
{
    LinkList s = (LinkList)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
}
bool DeQueue(LinkQueue &q,ElemType &e)
{
    if(q.rear==q.front)
        return false;
    LinkList p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if(q.rear==p)
    {
        q.rear = q.front;
    }
    free(p);
    return true;
}
