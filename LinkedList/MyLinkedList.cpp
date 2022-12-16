#include "MyLinkedList.h"


MyVector::MyVector()
{
    head = nullptr;
    size = 0;
}


MyVector::MyVector(int data)
{
    head = new Node(data);
    size = 1;
}

MyVector::MyVector(int size, int val)
{

    head = nullptr;
    this->size = 0;

    for(int i = 0; i < size; ++i)
    {
        pushBack(val);
    }
}

MyVector::MyVector(const MyVector &src)
{
    if(src.head == nullptr)
    {
        head = nullptr;
        size = 0;
    }
    else
    {   
        head = nullptr;
        size = 0;
        Node *current = src.head;
        for (int i = 0; i < src.size; i++)
        {
            pushBack(current->data);
            current = current->next;
        }
        std::cout << "SIZE :" << size << std::endl;
    }  


}

MyVector& MyVector::operator=(MyVector src)
{
    std::swap(head, src.head);
    std::swap(size, src.size);
    return *this;
}

void MyVector::insert(int data, int index)
{
    if(head == nullptr) // no head, so the new node becomes the head
    {
        Node *newNode = new Node(data);

        head = newNode;
        size++;

    } 
    else if(index > size) // if index is larger than the size, push the element to the end of the list
    {
        pushBack(data);
    } 
    else if(index == 0) // insertion at head case
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    } 
    else 
    {
        int counter = 0;
        int newIndex = index - 1;
        Node *current = head;

        while(counter != newIndex)
        {
            current = current->next;
            counter++;
        }
        Node *newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }


}

void MyVector::pushBack(int data)
{
    Node *newNode = new Node(data);

    if(head == nullptr) // no head, so the new node becomes the head
    {
        head = newNode;
        size++;
    } 
    else 
    {    
        Node *current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        size++;
    }
}


int MyVector::popBack()
{
    if(head == nullptr) // list is empty
    {
        throw std::out_of_range ("List is empty");
    } 
    if(head->next == nullptr) // if only there is  a head
    {
        int last = head->data;
        delete head;
        head = nullptr;
        size--;
        return last;
    }
    else 
    {
        Node *prev = head;
        Node *current = head->next;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        int last = current->data;
        delete current;
        prev->next = NULL;
        size--;
        return last; 
    }
}


void MyVector::remove(int index)
{
    if((size == 0) || (index < 0) || (index > size))
    {
        throw std::out_of_range("List is empty");
    } 
    else
    {
        
        if(index == 0) // removeing the head
        {
            Node *ref = head;       
            head = head->next;
            delete ref;
            ref = nullptr;
        }
        else
        {
            Node *node = head;
            for (int i = 0; i < index - 1; i++) {
                node = node->next;
            }
            Node *tmp = node->next;
            node->next = node->next->next;
            delete tmp;
        }

        size--;
    }
}


int& MyVector::at(int index)
{
    if((index < 0) || (index > size))
    {
        throw std::out_of_range("Index out of range");
    }

    int counter = 0;
    Node* current = head;

    while (counter != index)
    {
        current = current->next;
        counter++;
    }


    return current->data;
}
int MyVector::getSize()
{
    return size;
}

MyVector::~MyVector()
{
    Node* current = head;

    while(head != nullptr)
    {
        current = head;
        head = head->next;

        delete current;
    }
}

int& MyVector::operator[](int index)
{
    if(index < 0 || index > size)
    {
        throw std::out_of_range("Index out of range");
    }
    int counter = 0;
    Node* current = head;

    while (counter != index)
    {
        current = current->next;
        counter++;
    }


    return current->data;
}


std::ostream& operator<<(std::ostream & os,  MyVector& list)
{

    int size = list.getSize();

	os << "[";
	for(int i = 0; i < size; ++i)
	{
		os << list[i] << ", ";
	}
	os << "]\n";

	return os;
}
 