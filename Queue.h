#pragma once
#include<iostream>
#include<algorithm>
template <class T>

class Queue
{ // A finite ordered list with zero or more elements.
private:
	T* queue;           // array for queue elements
	int front;          // one counterclockwise from front
	int rear;               // array position of rear element
	int capacity;           // capacity of queue array

public:
	Queue(int queueCapacity = 10);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
	// Create an empty queue whose initial capacity is queueCapacity

};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template <class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

template <class T>
inline void Queue<T>::Push(const T& x) 
{// Add x at rear of queue.
	if ((rear + 1) % capacity == front)
	{// queue full, double capacity
	  // code to double queue capacity comes here

			// allocate an array with twice the capacity
		T* newQueue = new T[2 * capacity];

		// copy from queue to newQueue
		int start = (front + 1) % capacity;
		if (start < 2)
			// no wrap around
			std::copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{// queue wraps around
			std::copy(queue + start, queue + capacity, newQueue);
			std::copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		// switch to newQueue
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template <class T>
void Queue<T>::Pop() 
{// Delete front element from queue.
	if (IsEmpty()) throw "Queue is empty. Cannot delete.";
	front = (front + 1) % capacity;
	queue[front].~T();   // destructor for T
}
