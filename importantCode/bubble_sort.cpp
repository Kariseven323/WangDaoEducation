/**
 * @file bubble_sort.cpp
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
void st_init(SSTable &st,int len)
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
void swap(ElemType &a,ElemType &b)
{
    ElemType tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void BubbleSort(ElemType str[],int n)
{
    int i, j;
    bool flag;
    for (i = 0; i < n - 1;i++)
    {
        flag = false;
        for (j = n - 1; j > i;j--)
        {
            if(str[j-1]>str[j])
            {
                swap(str[i - 1], str[i]);
                flag = true;
            }
        }
        if(false==flag)
            return;
    }
}