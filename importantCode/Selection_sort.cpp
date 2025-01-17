/**
 * @file Selection_sort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-16
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
void SelectSort(ElemType str[],int n)
{
    int i, j, min;
    for (i = 0; i < n - 1;i++)
    {
        min = i;
        for (j = i + 1; j < n;j++)
        {
            if(str[j]<str[min])
            {
                min = j;
            }
        }
        if(min!=i)
            swap(str[i], str[min]);
    }
}