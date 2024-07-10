#include<iostream>
using namespace std;
#define QUEUE_EMPTY -1

class Node
{
    public:
        int data;
        Node *next;
};

class Queue
{
    Node *front, *rear;
    public:
        Queue();
        void enqueue(int);
        void dequeue();
        bool isEmpty();
        int rearElement();
        int frontElement();
        int elementsPresesntInQueue();
        void printQueue();
        ~Queue();
};

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

bool Queue::isEmpty()
{
    return (front == nullptr && rear == nullptr);
}

void Queue::enqueue(int item)
{
    Node *n;
    n = new Node;
    n->data = item;
    n->next = nullptr;

    if(isEmpty())       // If Queue is Empty then in front pointer keep the first node address
    {
        front = n;
        rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

void Queue::dequeue()
{
    Node *t;
    if(isEmpty())
        throw QUEUE_EMPTY;
    
    else if(front == rear)  // If only one node is present in Queue then simply delete it
    {
        delete front;
        front = rear = nullptr;
    }

    else
    {
        t = front;
        front = front->next;
        delete t;
    }
}

int Queue::rearElement()
{
    if(isEmpty())
        return QUEUE_EMPTY;
    else
        return rear->data;
}

int Queue::frontElement()
{
    if(isEmpty())
        return QUEUE_EMPTY;
    else
        return front->data;
}

int Queue::elementsPresesntInQueue()
{
    int count = 0;
    Node *temp = front;
    
    if(!isEmpty())
    {
        while(temp)
        {
            count++;
            temp = temp->next;
        }
    }
    return count;
}

void Queue::printQueue()
{
    Node *temp;
    if(!isEmpty())
    {
        temp = front;
        cout << endl
             << "The Elements of Queue are" << endl;

        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

Queue::~Queue()
{
    while(front)
        dequeue();
}

int main()
{
    Queue q1;

    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70);
    q1.enqueue(80);

    q1.printQueue();
    cout << endl
         << "Number of Elements present in Queue are: " << q1.elementsPresesntInQueue() << endl;

    q1.dequeue();
    q1.printQueue();
    cout << endl
         << "After delete element from Queue Number of Elements present in Queue are: " << q1.elementsPresesntInQueue() << endl;

         
    return 0;
}