/**
 * @file binary_search.cpp
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
typedef struct{
    ElemType *data;
    int TableLen;
} SSTable;
void ST_Init(SSTable &st,int len)
{
    st.TableLen = len;
    st.data = (ElemType *)malloc(sizeof(ElemType) * st.TableLen);
    int i;
    srand(time(NULL));
    for (i = 0; i < st.TableLen;i++)
    {
        st.data[i] = rand() % 100;
    }
}
void ST_print(SSTable st)
{
    for (int i = 0; i < st.TableLen;i++)
    {
        printf("%3d", st.data[i]);
    }
    printf("\n");
}
int BinarySearch(SSTable l, ElemType key)
{
    int low = 0, high = l.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (l.data[mid] == key)
            return mid;
        else if (l.data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int compare(const void *left,const void *right)
{
    return *(ElemType *)left - *(ElemType *)right;
}