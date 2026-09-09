#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    } 
};

class LinkedList
{
private:
    Node* head;
public: 
    LinkedList()
    {
        head = nullptr;
    }    
};

int main()
{

}