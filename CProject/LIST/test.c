#include <stdio.h>
#include "sqlist.h"
#include "sqlist.c"

void printSq(Sqlist T)
{
    int i;
    for(i=0;i<T.length;++i)
    {
        printf("%d\t",T.elem[i]);
    }
    putchar('\n');
}
int main()
{
    Sqlist L,P,C;
    int i,e;
    InitList_Sq(&L);
    InitList_Sq(&P);
    for(i=1;i<=5;i++)
    {
        ListInsert_Sq(&L,i,i);
        ListInsert_Sq(&P,i,i+10);
    }

    ListMerge_Sq(L,P,&C);

    printSq(L);
    printSq(P);
    printSq(C);
    if(GetElem_Sq(C,8,&e) == TRUE)
    {
        printf("线性表第8个元素为：%d\n",e);
    }
    else
    {
        puts("对不起，没有找到该元素！");
    }
    /*
    ClearList_Sq(L);
    DestroyList_Sq(L);
    
    printf("线性表为空吗？%d\n",ListEmpty_Sq(*L) == TRUE?TRUE:FALSE);
    for(i=0;i<5;i++)
    {
        printf("%d\t",L->elem[i]);
    }
    */
    DestroyList_Sq(&L);
    DestroyList_Sq(&P);
    DestroyList_Sq(&C);
    
    return 0;
}

