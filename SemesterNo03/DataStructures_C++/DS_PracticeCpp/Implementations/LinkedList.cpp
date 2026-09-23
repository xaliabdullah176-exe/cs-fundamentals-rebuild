// #include <iostream>
// using namespace std;

// class SinglyLinkedList
// {

//     class Node
//     {
//     public:
//         int data;
//         Node *next;
//         Node()
//         {
//             data = 0;
//             next = NULL;
//         }

//         Node(int data)
//         {
//             this->data = data;
//             next = NULL;
//         }
//     };

// private:
//     Node *head;
//     Node *tail;

// public:
//     SinglyLinkedList()
//     {
//         head = tail = NULL;
//     }

//     void push_front(int data) // O(1)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     void push_back(int data) // O(n)
//     {
//         Node *newNode = new Node(data);

//         if (head == NULL)
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             Node *temp = head;

//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
//     void pop_front(int target)
//     {
//         if (head == NULL)
//         {
//             cout << "List is Empty " << endl;
//             return;
//         }
//         Node *temp = head;
//         head = head->next;
//         temp->next = NULL;

//         delete temp;
//     }

//     void pop_back()
//     {
//         Node *temp = head;
//         if(head == NULL)
//         {
//             cout<<"Empty Nothing to delete"<<endl;
//         }
//         else
//         {
//         while(temp->next->next!=NULL)
//         {
//             temp = temp -> next;
           
            
//         }
//          delete temp;

//         }
//     }

//     void print_list()
//     {
//         if (head == NULL)
//         {
//             cout << "List is Empty" << endl;
//         }
//         else
//         {
//             Node *temp = head;

//             while (temp != NULL)
//             {
//                 cout << temp->data << " -> ";
//                 temp = temp->next;
//             }
//         }
//         cout << " NULL" << endl;
//     }
// };
// int main()
// {

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     SinglyLinkedList li;
//     li.push_front(20);
//     li.push_front(30);
//     li.print_list();

//     return 0;
// }




// Linked List New Implementation: 

#include <iostream>
using namespace std;

class LinkedList{
    
    class Node{
            int data;
            Node* next;
    public:
            Node()
            {
                data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                next = NULL;
            }
    };
    
    Node* head;
    Node* tail;
    
    public:
   LinkedList()
   {
    Node* NewNode = head;
   } 

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}