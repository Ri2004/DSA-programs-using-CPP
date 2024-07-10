#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class Stack
{
    Node *top;
    public:
        Stack();
        void push(int);
        void pop();
        int peek();
        bool isEmpty();
        void reverseStack(Stack &);
        void printStack();
        ~Stack();
};

Stack::Stack()
{
    top = nullptr;
}

void Stack::push(int item)
{
    Node *n;
    n = new Node;
    n->data = item;
    n->next = top;
    top = n;
}

void Stack::pop()
{
    Node *t;
    if(top)
    {
        t = top;
        delete t;
        top = top->next;
    }
}

int Stack::peek()
{
    if (top)
        return top->data;

    return -1;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

Stack::~Stack()
{
    while(top)
        pop();
}

void Stack::reverseStack(Stack &s)
{
    Stack s1, s2;
    while(!s.isEmpty())
    {
        s1.push(s.peek());
        s.pop();
    }
    while(!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    while(!s2.isEmpty())
    {
        s.push(s2.peek());
        s2.pop();
    }
}

void Stack::printStack()
{
    Node *temp;
    temp = top;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Stack s1;
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);

    cout << "After push in stack the stack is: " << endl;
    s1.printStack();

    s1.reverseStack(s1);
    cout << endl
         << "After reverse stack" << endl;
         
    s1.printStack();

    return 0;
}