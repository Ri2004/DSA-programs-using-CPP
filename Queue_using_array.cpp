#include<iostream>
using namespace std;
#define QUEUE_FULL 1
#define QUEUE_EMPTY -1

class Queue
{
    int capacity, front, rear, *ptr;
    public:
        Queue(int);
        void enqueue(int);
        void dequeue();
        bool isFull();
        bool isEmpty();
        int rearElement();
        int frontElement();
        int elementsPresesntInQueue();
        void printQueue();
        ~Queue();
};

// Initialize Member variables using constructor
Queue::Queue(int size)
{
    front = -1;
    rear = -1;
    capacity = size;
    ptr = new int[capacity];
}

// return true if Queue is full
bool Queue::isFull()
{
    return rear == capacity - 1;
}

// return true if Queue is empty
bool Queue::isEmpty()
{
    return (front == -1 && rear == -1);
}

// Insert Element in the Queue
void Queue::enqueue(int item)
{
    if(isFull())
        throw QUEUE_FULL;

    else if(isEmpty())
    {
        front++;
        ptr[++rear] = item;
    }
    else
        ptr[++rear] = item;
}

// Delete element from Queue
void Queue::dequeue()
{
    if(isEmpty())
        throw QUEUE_EMPTY;

    else if(front == rear)
        front = rear = -1;
    else
        front++;
}

// Method for return front element in Queue
int Queue::frontElement()
{
    return ptr[front];
}

// Method for return rear element in Queue
int Queue::rearElement()
{
    return ptr[rear];
}

// Return how many elements present in Queue
int Queue::elementsPresesntInQueue()
{
    int count = 0, i = front;

    if(isEmpty())
        return QUEUE_EMPTY;

    while(i<=rear)
    {
        i++;
        count++;
    }
    return count;
}

// Prints elements in the Queue
void Queue::printQueue()
{
    int i;
    if(isEmpty())
        throw QUEUE_EMPTY;
    
    else
    {
        i = front;
        cout << endl
             << "The Elements in Queue are" << endl;
        while (i <= rear)
        {
            cout << ptr[i] << " ";
            i++;
        }
    }
}

// Destructor
Queue::~Queue()
{
    delete[] ptr;
}

int main()
{
    Queue q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.printQueue();
    cout << endl
         << "Number of Elements in Queue are: " << q1.elementsPresesntInQueue() << endl;

    q1.dequeue();
    cout << endl
         << "Number of Elements in Queue are: " << q1.elementsPresesntInQueue() << endl;
    return 0;
}