#include "MyStack.h"
#include <iostream>



MyStack::MyStack()
{
    list = nullptr;
    top = nullptr;
}


MyStack::MyStack(MyStack &other)
{

    list = other.list;

    Node *current = list;
    while(current != nullptr)
    {
        push(current->data);
        current = current->next;
    }

    top = other.top;
}



MyStack::MyStack(int data)
{
    list = nullptr;
    Node *newNode = new Node(data);

    list = newNode;
    top = newNode;
}

MyStack::~MyStack()
{
    
    Node* current = list;

    while(list != nullptr)
    {
        current = list;
        list = list->next;

        delete current;
    }
}

void MyStack::push(int data)
{
    if(list == nullptr)
    {
        Node *newNode = new Node(data);
        list = newNode;
        top = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = list;
        list = newNode;
        top = list;

    }
}

int MyStack::pop()
{
    int data = 0;
    if(list == nullptr)
    {
        throw std::out_of_range("Stack empty");
    }
    else if(list->next == nullptr)
    {
        data = top->data;
        delete list;
        top = nullptr;
        list = nullptr;
    }
    else
    {
        Node *tmp = list; 
        data = list->data;
        list = list->next;
        top = list;
        delete tmp;
        tmp = nullptr;
    }
    return data;
}

int MyStack::peek()
{
    return top->data;   
}

void MyStack::print()
{
    print(list);
}


void MyStack::print(Node *top)
{
    if(top != nullptr)
    {
        std::cout << top->data << std::endl;
        print(top->next);
    }
}
