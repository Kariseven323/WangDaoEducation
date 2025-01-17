/**
 * @file Merge_sort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#define MaxSize 10
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
void Merge(ElemType str[], int low, int high, int mid)
{
    static ElemType tmp[MaxSize];
    int i, j, k;
    for (k = low; k <= high; k++)
    {
        tmp[k] = str[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (tmp[i] <= tmp[j])
            str[k] = tmp[i++];
        else
            str[k] = tmp[j++];
    }
    while (i <= mid)
    {
        str[k++] = tmp[i++];
    }
    while (j <= high)
    {
        str[k++] = tmp[j++];
    }
}
void MergeSort(ElemType str[],int low,int high)
{
    if(low<high)
    {
        int mid = (low + high) / 2;
        MergeSort(str, low, mid);
        MergeSort(str, mid + 1, high);
        Merge(str, low, mid, high);
    }
}