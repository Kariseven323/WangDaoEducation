/**
 * @file Liner_table.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList list_head_insert(LinkList &L)//头插法
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x!=9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
LinkList list_tail_insert(LinkList &L)//尾插法
{
    L = (LinkList)malloc(sizeof(LNode));
    int x;
    scanf("%d", &x);
    LNode *s, *r = L;
    while(x!=9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
void print(LinkList L)
{
    LNode *r = L->next;
    while(r!=NULL)
    {
        printf("%3d", r->data);
        r = r->next;
    }
    printf("\n");
}
LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p = p->next;
    }
    return p;
}
bool ListFrontInsert(LinkList L,int i,ElemType e)
{
    LinkList p = GetElem(L, i - 1);
    if(NULL==p)
    {
        return false;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool ListDelete(LinkList L,int i)
{
    LinkList p = GetElem(L, i - 1);
    if(NULL==p)
    {
        return false;
    }
    LinkList q;
    q = p->next;
    if(NULL==q)
    {
        return false;
    }
    p->next = q->next;
    free(q);
    return true;
}
LNode *ListReverse(LinkList L)
{
    LinkList L1=(LinkList)malloc(sizeof(LNode));
    L1->next = NULL;
    LinkList L2 = L->next;
    while(L2!=NULL)
    {
        LinkList p=(LinkList)malloc(sizeof(LNode));
        p->data = L2->data;
        p->next = L1->next;
        L1->next = p;
        L2 = L2->next;
    }
    return L1;
}
LinkList merge(LinkList L1, LinkList L2)
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *tail = L;
    LNode *p = L1->next;
    LNode *q = L2->next;

    while (p)
    {
        LNode *s = (LinkList)malloc(sizeof(LNode));
        s->data = p->data;
        tail->next = s;
        tail = tail->next;
        p = p->next;
    }

    while (q)
    {
        LNode *s = (LinkList)malloc(sizeof(LNode));
        s->data = q->data;
        tail->next = s;
        tail = tail->next;
        q = q->next;
    }

    tail->next = NULL;
    return L;
}