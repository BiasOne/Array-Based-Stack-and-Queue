#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>

class ABS 
{
private:
	static double scaleFactor;
	int capacity;
	int size;
	T* data;	
	
public:
	ABS();
	ABS(int capacity);
	ABS(const ABS& d);
	ABS& operator=(const ABS& d);
	ABS& operator+=(const ABS& d);
	void set(const ABS& d);
	void add(T value);
	void combine(const ABS& d);
	void addValues(T values[], unsigned int count);
	void print();
	~ABS();
	void push(T data);
	T pop();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	void resize(double scaleFactor);	
};
//******************************
//			
//******************************
template <class T>
double ABS<T>::scaleFactor = 2.0;
//******************************
//		Default constructor
//******************************
template <class T>
ABS<T>::ABS()
{	
	capacity = 1;
	size = 0;
	data = nullptr;
}
//******************************
//			Constructor
//******************************
template <class T>
ABS<T>::ABS(int capacity)
{	
	this->capacity = capacity;
	size = 0;
	data = new T[this->capacity];
}
//******************************
//			Copy Constructor 
//******************************
template <class T>
ABS<T>::ABS(const ABS& d)
{
	data = nullptr;
	set(d);
}
//******************************
//			Assignment operator
//******************************
template <class T>
ABS<T>& ABS<T>::operator=(const ABS& rhs)
{	
	set(rhs);
	return *this;
}
//******************************
//			Assignment operatorplus
//******************************
template <class T>
ABS<T>& ABS<T>::operator+=(const ABS& rhs)
{
	addValues(rhs.data, rhs.size);
	return *this;
}
template <class T>
void ABS<T>::combine(const ABS& d)
{
	*this += d;
}
//******************************
//			Code for Assignment opterator and constructor
//******************************
template <class T>
void ABS<T>::set(const ABS& d)
{
	delete[] data;
	capacity = d.capacity;
	size = d.size;	
	data = new T[d.capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = d.data[i];
	}
}
//******************************
//			ADD
//******************************
template <class T>
void ABS<T>::add(T value)
{
	if (data == nullptr)	{

		data = new T[1];
		data[0] = value;
		capacity = 1;
	}
	else if (size == capacity)
	{
		T* tempArray = new T[capacity + 1];
		for (int i = 0; i < size; i++)
			tempArray[i] = data[i];
		tempArray[size] = value;
		capacity++;
		delete[] data;
		data = tempArray;
	}
	else if (size < capacity)
	{
		data[size] = value;
	}
	size++;
}
template <class T>
void ABS<T>::addValues(T values[], unsigned int count)
{
	for (int i = 0; i < count; i++)
		add(values[i]);
}
//******************************
//			Print
//******************************
template <class T>
void ABS<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;
	}
}
//******************************
//			Destructor
//******************************
template <class T>
ABS<T>::~ABS()
{
	delete[] data;
}
//******************************
//			Push
//******************************
template <class T>
void ABS<T>::push(T data)
{
	add(data);
}
//******************************
//
//******************************
template <class T>
T ABS<T>::pop()
{
	if (size < 1 || capacity < 1) 
	{
		T* tempArray = new  T[(int)(capacity/scaleFactor)];
		for (int i = 0; i < size; i++)

			tempArray[i] = this->data[i];

		capacity = capacity/scaleFactor;
		delete[] this->data;
		this->data = tempArray;		
	}
	if(size==0)
	{
		throw runtime_error("An error has occurred.");		
		T removedValue = data[size-1];
		
		return removedValue;
	}	
	size--;
}
//******************************
//
//******************************
template <class T>
T ABS<T>::peek()
{
	if (size == 0 || capacity == 0)
	{
		throw runtime_error("An error has occurred. Stack is empty!");
			
	}
	T topOfStack = data[size - 1];
	return topOfStack;
}
	
//******************************
//
//******************************
template <class T>
unsigned int ABS<T>::getSize()
{
	return size;
}
//******************************
//
//******************************
template <class T>
unsigned int ABS<T>::getMaxCapacity()
{
	return capacity;
}
//******************************
//
//******************************
template <class T>
T* ABS<T>::getData()
{
	return data;
}
//******************************
//
//******************************
template <class T>
void ABS<T>::resize(double scaleFactor)
{
	T* tempData = new  T[(int)(capacity * scaleFactor)];
	for (int i=0; i < size; i++)
	{
		tempData[i] = data[i];			
	}
	capacity = capacity * scaleFactor;
	delete[] data;
	data = tempData;
}
//******************************
//
//******************************
