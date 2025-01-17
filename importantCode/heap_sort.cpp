/**
 * @file heap_sort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int TableLen;
} SSTable;
void ST_Init(SSTable &st, int len)
{
    st.TableLen = len;
    st.elem = (ElemType *)malloc(sizeof(ElemType) * st.TableLen);
    int i;
    srand(time(NULL));
    for (i = 0; i < st.TableLen; i++)
    {
        st.elem[i] = rand() % 100;
    }
}
void st_print(SSTable st)
{
    for (int i = 0; i < st.TableLen; i++)
    {
        printf("%3d", st.elem[i]);
    }
    printf("\n");
}
void swap(ElemType &a, ElemType &b)
{
    ElemType tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void AdjustDown(ElemType str[],int k,int len)
{
    int dad = k;
    int son = 2 * dad + 1;
    while(son<=len)
    {
        if(son+1<=len&&str[son]<str[son+1])
        {
            son++;
        }
        if(str[son]>str[dad])
        {
            swap(str[son], str[dad]);
            dad = son;
            son = 2 * dad + 1;
        }else
        {
            break;
        }
    }
}
void HeapSort(ElemType str[],int len)
{
    int i;
    for (i = len / 2; i >= 0;i--)
    {
        AdjustDown(str, i, len);
    }
    swap(str[0], str[len]);
    for (i = len - 1; i > 0;i--)
    {
        AdjustDown(str, 0, i);
        swap(str[0], str[i]);
    }
}