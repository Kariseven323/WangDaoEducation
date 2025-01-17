/**
 * @file BiTree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include "function.h"
using namespace std;
void PreOrder(BiTree p)
{
    if(p!=NULL)
    {
        putchar(p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
void InOrder(BiTree p)
{
    if(p!=NULL)
    {
        InOrder(p->lchild);
        putchar(p->data);
        InOrder(p->rchild);
    }
}
void PostOrder(BiTree p)
{
    if(p!=NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->data);
    }
}
int main()
{
    BiTree tree;
    char c;
    ptag_t phead=NULL, ptail=NULL, listpnew=NULL, pcur=NULL;
    BiTNode *pnew;
    while (scanf("%c", &c))
    {
        if(c=='\n')
        {
            break;
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        pnew->data = c;
        listpnew->p = pnew;
        if(NULL==tree)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        }else{
            ptail->pnext = listpnew;
            ptail = ptail->pnext;
        }
        if(NULL==pcur->p->lchild)
        {
            pcur->p->lchild = pnew;
        }
        else if (NULL == pcur->p->rchild)
        {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }
}