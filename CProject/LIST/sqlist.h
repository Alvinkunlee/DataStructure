#ifndef SQLIST_H
#define SQLIST_H

#include "common.h"
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

//定义顺序表内数据的数据类型
typedef int Elemtype;

//定义顺序表结构
typedef struct{
	Elemtype* elem;
	int length;
	int listsize;	
} Sqlist;

 //构造一个空的线性表
Status InitList_Sq(Sqlist* L);

// 销毁线性表
Status DestroyList_Sq(Sqlist* L);

//将线性表设为空
Status ClearList_Sq(Sqlist* L);

//若线性表为空则返回真，否则返回假
Status ListEmpty_Sq(Sqlist L);

//返回线性表L中元素个数
int ListLength_Sq(Sqlist L);

 //用e返回L中第i个数据元素的值
Status GetElem_Sq(Sqlist L,int i,Elemtype* e);

//返回L中第一个与e满足关系compare()的数据元素的位序，若这样的数据元素不存在则返回0
int LocateElem_Sq(Sqlist L,Elemtype e,Status (*compare)(Elemtype a,Elemtype b));

//在L中第i个位置之前插入新的数据元素e,L的长度加1
//1<=i<=L.length
Status ListInsert_Sq(Sqlist* L, int i, Elemtype e);

//在L中删除第i个元素，并将其值用e返回，L的长度减1
Status ListDelete_Sq(Sqlist* L,int i, Elemtype* e);

void ListMerge_Sq(Sqlist La,Sqlist Lb,Sqlist* Lc);

#endif
