#pragma once 

#include <iostream>
#include <cstring>



class MyVector
{
public:
	
	MyVector();
	MyVector(int size);
	MyVector(int size, int init);
	MyVector(const MyVector& other);

	friend std::ostream& operator<<(std::ostream & os,  MyVector& vector);
	MyVector& operator=(MyVector other);
	MyVector operator+(int num);
	MyVector operator-(int index);
	MyVector operator*(int num);
	int& operator[](int index);

	void shrink();
	void pushBack(int element);
	void insert(int element, int index);
	void remove(int index);
	int &at(int index);
	int popBack();
	int getSize();

	~MyVector();


private:
	void grow();
	void outOfRange(std::string msg);

private:
	int size = 0;
	int capacity = 0;
	int *arr;
};