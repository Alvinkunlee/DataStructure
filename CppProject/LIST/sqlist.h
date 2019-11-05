#ifndef SQLIST_H
#define SQLIST_H

#include "common.h"
//#include <iostream>
const int LIST_INIT_SIZE = 5;
const int LISTINCREMENT = 10;

template<class T>
class Sqlist{
	public:
		Sqlist(int=LIST_INIT_SIZE);
		~Sqlist()
        {
            delete []elem;
           // std::cout << "析构函数被调用" << std::endl;
        }
		bool ListInsert_sq(int,T);
		T ListDelete_sq(int);
		bool ListMerge_sq(const Sqlist<T>);
		bool DestroyList();
		bool ListEmpty() const;
		int ListLength() const{return length;}
		int ListSize() const {return listsize;}
		T GetElem(const int) const;
		int LocateElem(T,bool (*compare)(T,T)) const;
	private:
		T* elem;
		int length;
		int listsize;
};

#endif
