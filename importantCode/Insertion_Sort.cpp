/**
 * @file Insertion_Sort.cpp
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
void InsertSort(ElemType str[],int n)
{
    int i, j, insertVal;
    for (i = 1; i < n;i++)
    {
        insertVal = str[i];
        for (j = i - 1; j >= 0 && str[j] > insertVal;j--)
        {
            str[j + 1] = str[j];
        }
        str[j + 1] = insertVal;
    }
}