#pragma once 

#include <iostream>
#include <stdexcept>
#include "Node.h"


class MyVector
{
    public:

        MyVector();
        MyVector(int data);
        MyVector(int size, int val);
        MyVector(const MyVector &src);
       ~MyVector();

        void insert(int data, int index);
        void pushBack(int data);
        void removeFront();
        void remove(int index);
        int& at(int index);
        int popBack();
        int getSize();
        void print();
        
        int& operator[](int index);
        MyVector& operator=(MyVector src);
        friend std::ostream& operator<<(std::ostream& os, MyVector& list);


    private:
        Node *head;
        int size;
};  

