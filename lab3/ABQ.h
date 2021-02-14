#pragma once
#include <iostream>

using namespace std;

template <class T>

class ABQ
{
private:
	static double scaleFactor;
	int capacity;
	int size;
	T* data;
public:
	ABQ();
	ABQ(int capacity);
	ABQ(const ABQ& d);
	ABQ& operator=(const ABQ& d);
	void set(const ABQ& d);
	~ABQ();
	void enqueue(T data);
	T dequeue();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
};
//******************************
//			
//******************************
template <class T>
double ABQ<T>::scaleFactor = 2.0;
//******************************
//			
//******************************
template <class T>
ABQ<T>::ABQ()
{
	capacity = 1;
	size = 0;
	data = new T[capacity];
}
//******************************
//
//******************************
template <class T>
ABQ<T>::ABQ(int capacity)
{
	this->capacity = capacity;
	this->size = size;
	this->data = new T[this->capacity];
}
//******************************
//
//******************************
template <class T>
ABQ<T>::ABQ(const ABQ& d)
{
	set(d);
}
//******************************
//
//******************************
template <class T>
ABQ<T>& ABQ<T>::operator=(const ABQ& d)
{
	delete[] this->data;
	set(d);
	return *this;
}
//******************************
//
//******************************
template <class T>
void ABQ<T>::set(const ABQ& d)
{
	this->capacity = d.capacity;
	this->size = d.size;
	this->data = new T[this->capacity];

	for (int i = 0; i < size; i++)
	{
		this->data[i] = d.data[i];
	}
}
//******************************
//
//******************************
template <class T>
ABQ<T>::~ABQ()
{
	delete[] data;
}
//******************************
//
//******************************
template <class T>
void ABQ<T>::enqueue(T data)
{
	if (this->data == nullptr)
	{
		this->data = new T[1];
		this->data[0] = data;

		capacity = 1;
		size = 1;
	}
	else if (size == capacity)
	{
		T* tempArray = new  T[(int)(capacity * scaleFactor)];
		for (int i = 0; i < size; i++)

			tempArray[i] = this->data[i];

		capacity = capacity * scaleFactor;
		delete[] this->data;
		this->data = tempArray;
	}
	this->data[size] = data;

	size++;
}
//******************************
//
//******************************
template <class T>
T ABQ<T>::dequeue()
{
	if (size < 1 || capacity < 1)
	{
		T* tempArray = new  T[(int)(capacity / scaleFactor)];
		for (int i = 0; i < size; i++)

			tempArray[i] = this->data[i];

		capacity = capacity / scaleFactor;
		delete[] this->data;
		this->data = tempArray;
	}
	if (size == 0)
	{
		throw runtime_error("An error has occurred.");
		T removedValue = data[size - 1];
		size--;
		return removedValue;
	}
}
//******************************
//
//******************************
template <class T>
T ABQ<T>::peek()
{
	if (size == 0 || capacity == 0)
	{
		throw runtime_error("An error has occurred. Stack is empty!");
		T topOfStack = data[size - 1];
		return topOfStack;
	}

}
//******************************
//
//******************************
template <class T>
unsigned int ABQ<T>::getSize()
{
	return size;
}
//******************************
//
//******************************
template <class T>
unsigned int ABQ<T>::getMaxCapacity()
{
	return capacity;
}
//******************************
//
//******************************
template <class T>
T* ABQ<T>::getData()
{
	return data;
}

