#include<iostream>
using namespace std;
class Queue{
   int *arr;
   int size, rear, front;
    int count;
   public:
     Queue(int size=5){
          this->size = size;
	arr = new int[size];
	front=rear=-1;
         count = 0;
     }
	bool isEmpty()
	{
		return count==0;
	}
	bool isFull()
	{
		return count==size;
	}
	void enqueue(int data)
	{
		if(isFull())
		{
			cerr<<"Queue overflow"<<endl;
			return;
		}
		if(front == -1)
        {
            front = 0;
        }
        rear = (rear+1)%size;
		arr[rear] = data;
        count++;
	}
    void dequeue()
    {
        if(isEmpty())
		{
			cerr<<"Queue underflow"<<endl;
			return;
		}
        front = (front+1)%size;
        count--;
    }
	void display()
	{
		if(isEmpty())
		{
			cerr<<"Queue underflow"<<endl;
			return;
		}
		cout<<"Queue : [";
        int index = front;
		for(int i=1;i<count;i++)
		{
			cout<<arr[index]<<" , ";
            index = (index + 1)%size;
		}
		cout<<arr[index]<<"]"<<endl;
	}
          
    
     ~Queue(){
	delete [] arr;
	}
};

int main(){
	Queue q;
	q.enqueue(5);
	q.enqueue(55);
	q.enqueue(51);
	q.enqueue(501);
	q.enqueue(15);
    q.dequeue();
	q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.enqueue(100);
    while(!q.isEmpty()){
    	q.display();
        q.dequeue();
    }
   return 0;
}



#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data, Node* temp=NULL)
    {
        this->data = data;
        next = temp;
    }
};

class Queue{
    Node* front;
    Node* rear;
    public:
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void enqueue(int data)
    {
        Node* nn = new Node(data);
        if(isEmpty())
        {
            front = rear = nn;
        }
        rear->next = nn;
        rear = nn;
    }
    void dequeue(){
        if(isEmpty())
        {
            cerr<<"Queue Underflow"<<endl;
            return;
        }
        if(front==rear)
        {
            delete front;
            front = rear = NULL;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    void display()
    {
        if(isEmpty())
        {
            cerr<<"Queue Underflow"<<endl;
            return;
        }
        Node* temp = front;
        cout<<"Queue [";
        while(temp!=rear)
            {
                cout<<temp->data<<" , ";
                temp = temp->next;
            }
        cout<<temp->data<<"]\n";
    }
    void clear()
    {
        while(!isEmpty()){
            dequeue();
        }
    }
    ~Queue()
    {
        clear();
    }
};

int main()
{
    Queue q;
	q.enqueue(5);
	q.enqueue(55);
	q.enqueue(51);
	q.enqueue(501);
	q.enqueue(15);
    q.dequeue();
	q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.enqueue(100);
    while(!q.isEmpty()){
    	q.display();
        q.dequeue();
    }
    return 0;
}


