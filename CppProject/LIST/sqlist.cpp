#include "sqlist.h"
#include <exception>
#include <iostream>

using namespace std;

void check(int n,int start,int end,const char* msg ="输入n值越界，请重新输入！")
{
	try{
		if(n<start || n>end)
			throw out_of_range(msg);
	}catch(const out_of_range& e){
		cout << "边界异常：" << e.what() << endl;
	}
	
}

template<class T>
bool equal(T a, T b)
{
    return a == b ? true:false;
}

template<class T>
Sqlist<T>::Sqlist(int len)
{
	try{
		elem = new T[len];
		length = 0;
		listsize = len;
	}catch(const bad_alloc& e){
		cout << "分配内存异常:" << e.what() << endl;
	}
}

//注意此处1<=i<=L.length+1
template<class T>
bool Sqlist<T>::ListInsert_sq(int n,T e)
{
	//if(n<1 || n>length+1) return false;  //i值不合法
	check(n,1,length+1);
	if(length >= listsize)
	{
		T* temp = elem;
        try{
            elem = new T[listsize+LISTINCREMENT];
        }catch(const bad_alloc& e){
            cout << "内存分配异常：" << e.what() << endl;
        }
		for(int i=0; i <length; ++i)
		{
			elem[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;		
		listsize += LISTINCREMENT; 
	}
	T* q = elem+n-1;
	for(T* p= elem+length-1;p>=q; --p) *(p+1) = *p;

    	*q = e;
	++length;
	return true;
}

template<class T>
T Sqlist<T>::ListDelete_sq(int i)
{
	check(i,1,length+1);
    T* p = elem+i-1;
    T temp = *p;
    T* q = elem+length-1;
    while(p<q)
    {
        *p = *(p+1);
        ++p;
    }
    --length;
    return temp;
}

template<class T>
bool Sqlist<T>:: ListMerge_sq(const Sqlist<T> b)
{
    //如果合并列表的长度大于listsize则重新分配存储空间
	if(length+b.ListLength() >= listsize)
	{
		T* temp = elem;
        try{
            elem = new T[length+b.ListSize()];
        }catch(const bad_alloc& e){
            cout << "内存分配异常：" << e.what() << endl;
        }
		for(int i=0; i <length; ++i)
		{
			elem[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;		
		listsize += b.listsize; 
	}
    T* pa_last = elem + length -1;
    T* pb = b.elem;
    T* pb_last = b.elem+b.ListLength()-1;
    while(pb<=pb_last)
    {
        *(++pa_last) = *pb++;
        ++length;
    }
    return true;
}

template<class T>
bool Sqlist<T>::DestroyList()
{
    length = 0;
    listsize = 0;
    delete[] elem;
    elem = nullptr;
    //cout << "线性表销毁！" << endl;
    return true;
}

template<class T>
bool Sqlist<T>::ListEmpty() const
{
    return length == 0 ? true:false;
}

template<class T>
T Sqlist<T>:: GetElem(const int n) const
{
    check(n,0,length-1);
    return elem[n];
}

template<class T>
int Sqlist<T>::LocateElem(T e,bool (*compare)(T a,T b)) const
{
    int i=1;
    T* p = elem;
    while(i<=length && !(*compare)(*p++,e)) ++i;
    if(i<=length)
        return i;
    else return 0;
}
