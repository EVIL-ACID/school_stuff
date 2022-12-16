

struct Node
{
    int data;
    Node *next;
    Node(int Data) : data(Data), next(nullptr) {}
    Node(int Data, Node *Nex) : data(Data), next(Nex) {}
    Node() : next(nullptr) {}
};