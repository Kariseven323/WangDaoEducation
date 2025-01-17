/**
 * @file function.h
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
typedef char BiElemType;
typedef struct BiTNode{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;
typedef struct tag{
    BiTree p;
    struct tag *pnext;
} tag_t, *ptag_t;