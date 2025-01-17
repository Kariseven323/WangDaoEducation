/**
 * @file binary_sort_tree.cpp
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
typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BiTree;
int BST_Insert1(BiTree &t,KeyType k)//易理解版本
{
    if(NULL==t)
    {
        t = (BiTree)malloc(sizeof(BSTNode));
        t->key = k;
        t->lchild = t->rchild = NULL;
        return 1;
    }
    BiTree p = t, parent;
    while(p)
    {
        parent = p;
        if(k==p->key)
        {
            return 0;
        }else if(k<p->key)
        {
            p = p->lchild;
        }else{
            p = p->rchild;
        }
    }
    BiTree pnew = (BiTree)malloc(sizeof(BSTNode));
    pnew->key = k;
    pnew->lchild = pnew->rchild = NULL;
    if(k>parent->key)
    {
        parent->rchild = pnew;
    }else{
        parent->lchild = pnew;
    }
}
int BST_Insert2(BiTree &t,KeyType k)//递归版本
{
    if(NULL==t)
    {
        t = (BiTree)malloc(sizeof(BSTNode));
        t->key = k;
        t->lchild = t->rchild = NULL;
    }else if(k==t->key)
    {
        return 0;
    }else if(k<t->key)
    {
        return BST_Insert2(t->lchild, k);
    }else{
        return BST_Insert2(t->rchild, k);
    }
}
void Creat_BST(BiTree &t, KeyType str[], int n)
{
    t = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert2(t, str[i]);
        i++;
    }
}
BSTNode *BST_Search(BiTree t,KeyType key,BiTree &p)
{
    p = NULL;
    while(t!=NULL&&key!=t->key)
    {
        p = t;
        if(key<t->key)
            t = t->lchild;
            else
                t = t->rchild;
    }
    return t;
}
void DeleteNode(BiTree &root, KeyType x)
{
    if (root == NULL)
        return;
    if (root->key < x)
    {
        DeleteNode(root->lchild, x);
    }
    else if (root->key > x)
    {
        DeleteNode(root->rchild, x);
    }
    else
    {
        if (root->lchild == NULL)
        {
            BiTree tempNode = root;
            root = root->rchild;
            free(tempNode);
        }
        else if (root->rchild == NULL)
        {
            BiTree tempNode = root;
            root = root->lchild;
            free(tempNode);
        }
        else
        {
            BiTree tempNode = root->lchild;
            while (tempNode->rchild != NULL)
            {
                tempNode = tempNode->rchild;
            }
            root->key = tempNode->key;
            DeleteNode(root->lchild, tempNode->key);
        }
    }
}