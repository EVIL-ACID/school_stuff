

#pragma once

struct Node
{
    int data;
    Node *next;
    Node(int Data) : data(Data), next(nullptr) {}
    Node(int Data, Node *Nex) : data(Data), next(Nex) {}
    Node() : next(nullptr) {}
};

class MyStack
{

public:
    MyStack();
    MyStack(int data);
    MyStack(MyStack &other);
    ~MyStack();

    void push(int data);
    int pop();
    int peek();
    void print();

private:
    Node *list;
    Node *top;

    void print(Node *top);
};

