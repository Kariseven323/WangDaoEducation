/**
 * @file Sequential_Search.cpp
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
int Search_Seq(SSTable st,ElemType key)
{
    st.data[0] = key;
    int i;
    for (i = st.TableLen - 1; st.data[i] != key;--i)
    {
        return i;
    }
}
void ST_Init(SSTable &st,int len)
{
    st.TableLen = len + 1;
    st.data = (ElemType *)malloc(sizeof(ElemType) * st.TableLen);
    int i;
    srand(time(NULL));
    for (i = 1; i < st.TableLen;i++)
    {
        st.data[i] = rand() % 100;
    }
}
void st_print(SSTable st)
{
    for (int i = 1; i < st.TableLen;i++)
    {
        printf("%3d", st.data[i]);
    }
    printf("\n");
}