#include <iostream>
#include "sqlist.h"
#include "sqlist.cpp"

using namespace std;

int main(int argc, char** argv) {
	Sqlist<int> sq{},sb{5};
	for(int i=1; i<=2; ++i)
	{
		sq.ListInsert_sq(i,i);
        sb.ListInsert_sq(i,i+4);
	}
	//sq.ListInsert_sq(7,1);
    //cout << "删除元素:" << sq.ListDelete_sq(4) << endl;
    sq.ListMerge_sq(sb);
	for(int i=0; i<sq.ListLength(); ++i)
	{
		cout << sq.GetElem(i) << '\t';
	}
	cout << endl;
    cout << "第５个元素为：" << sq.LocateElem(5,equal) << endl;
	cout << "线性表元素个数：" << sq.ListLength() << endl;
	cout << "线性表长度：" << sq.ListSize() << endl;
    sq.DestroyList();
    sb.DestroyList();
	return 0;
}
