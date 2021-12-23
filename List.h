#pragma once
#include<iostream>
using namespace std;

class List
{
private:
	int* items;
	int itemCount;//삭제와 삽입에 따라 값 변경
	int size;

public:
	List();
	~List();
	int getItem(int index);
	void addItem(int itm);
	void insertItem(int index, int itm);//뒤에 밀리는 것도 고려.
	int removeAt(int index);
	int removeItem(int itm);//삭제하면 앞으로 당겨오는 것 고려.
	void concat(List& list);
	void print();
};
