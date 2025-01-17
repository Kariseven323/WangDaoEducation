/**
 * @file Sequence_table.cpp
 * @author your name (you@domain.com)
 * @brief 顺序表的增删改查
 * @version 0.1
 * @date 2025-01-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#define Maxsize 100
using namespace std;
typedef int ElemType;
typedef struct {
    int data[Maxsize];
    int length;
} SqList;
bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.length+1)
    return false;
    if(L.length>=Maxsize)
        return false;
    for (int j = L.length; j >= i;j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length += 1;
    return true;
}
void PrintList(SqList L)
{
    for (int i = 0; i < L.length;i++)
    {
        printf("%4d", L.data[i]);
    }
    printf("\n");
}
bool ListDelete(SqList &L, int i, ElemType &e)
{
    if(i<1||i>L.length)
        return false;
    e = L.data[i - 1];
    int j;
    for (j = i; j < L.length;j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
int LocateElem(SqList L,ElemType element)
{
    int i;
    for (i = 0; i < L.length;i++)
    {
        if(element==L.data[i])
        {
            return i + 1;
        }
    }
    return 0;
}