#include<iostream>
using namespace std;
#define QUEUE_EMPTY -1

class Node
{
    public:
        int data;
        Node *next, *prev;
};

class Deque
{
    Node *front, *rear;
    public:
        Deque();
        void insertFromRear(int);
        void insertFromFront(int);
        void deleteFromFront();
        void deleteFromRear();
        int getFrontElement();
        int getRearElement();
        bool isEmpty();
        void printQueue();
        ~Deque();
};

Deque::Deque()
{
    front = nullptr;
    rear = nullptr;
}

bool Deque::isEmpty()
{
    return (front == nullptr && rear == nullptr);
}

void Deque::insertFromRear(int item)
{
    Node *n;
    n = new Node;
    n->data = item;
    n->prev = n->next = nullptr;

    if(isEmpty())
        front = rear = n;
    
    else
    {
        rear->next = n;
        n->prev = rear;
        rear = n;
    }
}

void Deque::insertFromFront(int item)
{
    Node *n;
    n = new Node;
    n->data = item;
    n->prev = n->next = nullptr;

    if(isEmpty())
        front = rear = n;
    
    else
    {
        front->prev = n;
        n->next = front;
        front = n;
    }
}

void Deque::deleteFromFront()
{
    Node *d;

    if(isEmpty())
        throw QUEUE_EMPTY;
    
    else if(front == rear)
    {
        cout << endl
             << "The element of deleted node is " << front->data << endl;
        delete front;
        front = rear = nullptr;
    }

    else
    {
        front = front->next;
        cout << endl
             << "The Element of deleted node is: " << front->prev->data << endl;

        delete front->prev;
        front->prev = nullptr;
    }
}

void Deque::deleteFromRear()
{
    if(isEmpty())
        throw QUEUE_EMPTY;
    
    else if(front == rear)
    {
        cout << endl
             << "The element of deleted node is " << rear->data << endl;
        delete rear;
        front = rear = nullptr;
    }

    else
    {
        rear = rear->prev;
        cout << endl
             << "The data of deleted node is " << rear->next->data << endl;

        delete rear->next;
        rear->next = nullptr;
    }
}

void Deque::printQueue()
{
    Node *temp;

    if(isEmpty())
        throw QUEUE_EMPTY;
    
    else
    {
        temp = front;
        cout << endl
             << "The elements of Queue are " << endl;

        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int Deque::getFrontElement()
{
    return front->data;
}

int Deque::getRearElement()
{
    return rear->data;
}

Deque::~Deque()
{
    while(front)
        deleteFromFront();
}

int main()
{
    Deque dq1;

    dq1.insertFromRear(20);
    dq1.insertFromRear(30);
    dq1.insertFromRear(40);
    dq1.insertFromFront(50);
    dq1.insertFromFront(60);
    dq1.insertFromFront(70);

    dq1.printQueue();

    dq1.deleteFromRear();
    dq1.deleteFromFront();

    dq1.printQueue();
    return 0;
}