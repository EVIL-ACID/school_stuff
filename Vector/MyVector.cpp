#include "MyVector.h"


MyVector::MyVector()
{
	this->capacity = 10;
	arr = new int[this->capacity];
}

MyVector::MyVector(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
}

MyVector::MyVector(int capacity, int init)
{
	arr = new int[capacity];

	for(int i = 0; i < capacity; ++i)
	{
		arr[i] = init;
	}
}

MyVector::MyVector(const MyVector& other)
{
		size = other.size;
		capacity = other.capacity;
		arr = new int[size];	

		for(int i = 0; i < size; ++i)
		{
			arr[i] = other.arr[i];
		}
}


MyVector& MyVector::operator=(MyVector other)
{
	std::swap(size, other.size);
	std::swap(capacity, other.capacity);
	std::swap(arr, other.arr);
	return *this;
}


int MyVector::getSize()
{
	return size;
}


void MyVector::shrink()
{

	size_t toShrink = size * 3;
	if(capacity >= toShrink)
	{
		size_t newSize = capacity / 2; 
		int *newArray = new int[newSize];

		for(int i = 0; i < size; ++i)
		{
			newArray[i] = arr[i];
		}

		delete [] arr;
		arr = newArray;
		capacity = newSize;
	}
}

void MyVector::pushBack(int element)
{

	if(size >= capacity)
	{
		grow();
	}

	arr[size] = element;
	size++;
}

int MyVector::popBack()
{
	if(size < 0)
	{
		outOfRange("popBack");
	}

	shrink();

	int last = arr[size];
	arr[size] = 0;
	size--;
	return last;
}

void MyVector::insert(int element, int index)
{

    if(index < 0)
    {
    	outOfRange("Insert");
    }


    if(index >= size)
    {
    	pushBack(index);
    }

    else
    {
    	if(size >= capacity)
		{
			grow();
		}

		for(int i = size - 1; i >= index ; --i)
		{
			arr[i + 1] = arr[i];
		}

		arr[index] = element;
		size++;
    }



}

void MyVector::remove(int index)
{
	if(index < 0 || index >= size)
	{
		outOfRange("Remove");
	}

	
	shrink(); 

	for(int i = index; i < size - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}

	--size;

}


int &MyVector::at(int index)
{
	if(index < 0 || index >= size)
	{
		outOfRange("At");
	}

	return arr[index];
}

void MyVector::grow()
{

	size_t newSize = capacity * 2;
	int *newArray = new int[newSize];

	for(int i = 0; i < size; ++i)
	{
		newArray[i] = arr[i];
	}

	delete [] arr;
	arr = newArray;
	capacity = newSize;
}

MyVector MyVector::operator+(int num)
{
	MyVector vec = *this;
	pushBack(num);
	return vec;
} 


MyVector MyVector::operator*(int num)
{

	MyVector current(size);

	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < num; ++j)
		{
			current.pushBack(arr[i]);
		}
	}

	return current;
}

MyVector MyVector::operator-(int num)
{
	MyVector current = *this;

	for(int i = 0; i < size; ++i)
	{
		if(arr[i] == num)
		{
			remove(i);
			return current;
		}
	}

	return current;
}

int& MyVector::operator[](int index)
{
	if(index < 0 || index >= size)
	{
		outOfRange("At");
	}

	return arr[index];
}

void MyVector::outOfRange(std::string msg)
{
	std::cout << msg << " - Index out of range\n";
	exit(0);
}

std::ostream& operator<<(std::ostream & os,  MyVector& vector)
{

	os << "[";
	for(int i = 0; i < vector.getSize(); ++i)
	{
		os << vector[i] << ", ";
	}
	os << "]\n";

	return os;
}
 
MyVector::~MyVector()
{
	if(arr != NULL)
	{
		delete [] arr;
		arr = nullptr;
	}
}
