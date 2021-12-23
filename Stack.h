#pragma once

#include<iostream>
#include<algorithm>

template<typename T>
class Stack {

private:
	T* stack; // 스택 원소를 위한 배열 
	int top; // top 원소의 위치
	int capacity; // 스택 배열의 크기

public:

	Stack(int stackCapacity = 10);
	// Create an empty stack whose initial capacity is stackCapacity.

	bool IsEmpty() const;
	// If number of elements in the stack is 0, return true else return false.

	T& Top() const;
	// Return top element of stack.

	//void ChangeSize1D(T*& a, const int oldSize, const int newSize);
	
	void Push(const T& item);
	// Insert item into the top of the stack.

	void Pop();
	// Delete the top element of the stack
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;

}

template <class T>
inline bool  Stack<T>::IsEmpty() const
{
	return top == -1;
}

template <class T>
inline T& Stack<T>::Top() const
{
	if (IsEmpty()) throw "Stack is empty";
	return stack[top];
}

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];                                  // new array
	int number = std::min(oldSize, newSize);  // number to copy
	std::copy(a, a + number, temp);
	delete[] a;                             // deallocate old memory
	a = temp;
}


template <class T>
void Stack<T>::Push(const T& x)
{	// Add x to the stack.
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{	// Delete top element from the stack.
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T();   // destructor for T
}
