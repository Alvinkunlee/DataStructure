#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"


Status InitList_Sq(Sqlist* L)
{
    L->elem = (Elemtype*)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList_Sq(Sqlist* L)
{
    L->length = 0;
    L->listsize = 0;
    free(L->elem);
    L = NULL;
    //printf("线性表销毁！");
    return OK;
}

Status ClearList_Sq(Sqlist* L)
{
    int i;
    for(i=0;i<L->length;++i)
    {
        L->elem[i] = 0;
    }
    L->length = 0;
    return OK;
}

Status ListEmpty_Sq(Sqlist L)
{
    return L.length ==0 ? TRUE : FALSE;
}

int ListLength_Sq(Sqlist L)
{
    return L.length;
}

Status GetElem_Sq(Sqlist L, int i, Elemtype* e)
{
    if(i<1 || i>L.length+1)
        return ERROR;
    *e = L.elem[i-1];
    return OK;
}

Status ListInsert_Sq(Sqlist* L, int i, Elemtype e)
{
    Elemtype* q, *p;
    if(i<1||i>L->length+1)
        return ERROR;

    if(L->length > L->listsize)
    {
        Elemtype* newBase = (Elemtype*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(Elemtype));
        if(!newBase) return ERROR;
        L->elem = newBase;
        L->listsize += LISTINCREMENT;
    }

    for(q=&(L->elem[i-1]),p=&(L->elem[L->length-1]);p>=q;--p)
        *(p+1) = *p;
    
    *q = e;
    ++L->length;
    return OK;
}

//在L中删除第i个元素，并将其值用e返回，L的长度减1
Status ListDelete_Sq(Sqlist* L,int i, Elemtype* e)
{
    Elemtype *q,*p;
    if(i<1 || i > L->length+1)
        return ERROR;

    q = &L->elem[i-1];
    e = q;
    p = L->elem+L->length-1;
    while(q<=p)
    {
        *q = *(q+1);
        q++;
    }
    --L->length;
    return OK;
}


int LocateElem_Sq(Sqlist L,Elemtype e,Status (*compare)(Elemtype a,Elemtype b))
{
    int i=0;
    Elemtype* p = L.elem;
    while(i<L.length && !(*compare)(*p++,e)) ++i;
    if(i<=L.length) return i;
    else return 0;
}


void ListMerge_Sq(Sqlist La,Sqlist Lb,Sqlist* Lc)
{
    Elemtype *pa=La.elem,*pb=Lb.elem,*pc;
    Elemtype *pa_last = La.elem+La.length-1,*pb_last = Lb.elem+Lb.length-1;
    Lc->listsize = Lc->length = La.length+Lb.length;
    pc = Lc->elem = (Elemtype*)malloc(Lc->listsize*sizeof(Elemtype));
    
    if(!pc) exit(OVERFLOW);

    while(pa<=pa_last && pb<=pb_last){
        if(*pa<=*pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
}
