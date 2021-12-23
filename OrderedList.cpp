#include "OrderedList.h"
OrderedList::OrderedList()//생성자
{
	itemCount = 0;
	size = 5;
	items = new int[size];
}

OrderedList::~OrderedList()//소멸자
{
	delete[] items;
}

int OrderedList::getItem(int index)//특정위치의 값을 가져오는 함수
{
		int answer = -99999;
		if (index < itemCount) {//배열에 있는 index값을 넣어주면 그 값을 리턴하도록 하는 코드
			answer = items[index];
		}
		return answer;    //배열을 벗어나는 index값을 넣으면 -99999를 반환한다.                                            
}

void OrderedList::addItem(int itm)//리스트에 값을 추가하는 함수
{
	if (itemCount >= size)
	{
		int newSize = size * 2;//사이즈를 두배로 늘려준다.
		int* newItem = new int[newSize];//새로운 배열을 동적으로 할당
		for (int i = 0; i < itemCount; i++)
			newItem[i] = items[i];//items 안의 값들을 newItem으로 복사
		delete[]items;//items를 삭제
		items = new int[newSize];
		for (int j = 0; j < itemCount; j++)
			items[j] = newItem[j];//items에 newItem을 복사
		size = newSize;
	}

	int pos;
	for (pos = 0; pos < itemCount; pos++) {//순서대로 정렬하기 위한 부분
		if (items[pos] > itm)
			break;
	}
	itemCount++;
	for (int i = itemCount - 1; i > pos; i--)
		items[i] = items[i - 1];
	items[pos] = itm;
}

int OrderedList:: removeAt(int index)//해당 인덱스의 값을 삭제하고 그 값을 리턴해주는 함수
{
	int answer = 0;//answer값 초기화
	if (index < itemCount) {
		answer = items[index];
		for (int i = index; i < itemCount - 1; i++) {  //값을 당겨오는 부분
			items[i] = items[i + 1];
		}
		itemCount--;//itemCount를 1 줄이는 코드
		return answer;
	}
	else if (index >= itemCount) {//인덱스가 itemCount를 넘어가면 -99999를 리턴
		return -99999;
	}
}

int OrderedList:: removeItem(int itm) {//배열의 앞에서부터 찾았을 때 itm과 일치하는 첫번째 값을 삭제하는 함수
	int answer = 0;
	for (int i = 0; i < size; i++) {//배열 전체를 돌며 검사
		if (items[i] == itm) {//itm과 일치하는 값이 items에 있다면
			answer = i;
			for (int j = answer; j < itemCount - 1; j++) {//값을 당겨오는 부분
				items[j] = items[j + 1];
			} 
			itemCount--; //itemCount를 1 줄이는 코드 
			return answer;
		}
		if ((answer < 0) || (answer >= itemCount)) {//범위 내에서 answer를 찾지 못해서 answer 값이 -1인 경우 -99999를 리턴
			return -99999;
		}
	}
}

void OrderedList:: concat(OrderedList& olist)// 두 개의 리스트를 연결하는 함수
{
	int newSize = size + olist.size;//두 리스트의 size를 합친 값을 newSize에 저장한다.
	int newCount = itemCount + olist.itemCount;//두 리스트의 itemCount를 합친 값을 newCount에 저장한다.
	int* newItems = new int[newCount];
	for (int i = 0; i < itemCount; i++) {//앞 list의 items의 값들을  newItems에 복사해준다.
		newItems[i] = items[i];
	}
	for (int j = 0; j < olist.itemCount; j++) {//뒷 list의 items의 값들을 newItems에 복사해준다.
		newItems[(j + itemCount)] = olist.items[j];
	}
	size = newSize;
	delete[] items;
	items = new int[newSize];
	itemCount = 0;
	for (int k = 0; k < newCount; k++) {//newItems의 값들을 llist의 items에 복사해준다.
		this->addItem(newItems[k]);
	}

}
void OrderedList:: print()//list 안의 모든 값을 출력해주는 함수
{
	for (int i = 0; i < itemCount; i++) {
		cout << items[i] << " ";
	}
}
