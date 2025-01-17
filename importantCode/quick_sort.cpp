/**
 * @file quick_sort.cpp
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
    ElemType *elem;
    int TableLen;
} SSTable;
void ST_Init(SSTable &st, int len)
{
    st.TableLen = len;
    st.elem = (ElemType *)malloc(sizeof(ElemType) * st.TableLen);
    int i;
    srand(time(NULL));
    for (i = 0; i < st.TableLen;i++)
    {
        st.elem[i] = rand() % 100;
    }
}
void st_print(SSTable st)
{
    for (int i = 0; i < st.TableLen;i++)
    {
        printf("%3d", st.elem[i]);
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
int Partition(ElemType str[],int low,int high)
{
    ElemType pivot = str[low];
    while(low<high)
    {
        while(low<high&&str[high]>=pivot)
        {
            high--;
        }
        if (low < high)
        {
            str[low] = str[high];
        }
        while(low<high&&str[low]<=pivot)
        {
            low++;
        }
        if(low<high)
        {
            str[high] = str[low];
        }
    }
    str[low] = pivot;
    return low;
}
void QuickSort(ElemType str[],int low,int high)
{
    if(low<high)
    {
        int pivotpos = Partition(str, low, high);
        QuickSort(str, low, pivotpos - 1);
        QuickSort(str, pivotpos + 1, high);
    }
}