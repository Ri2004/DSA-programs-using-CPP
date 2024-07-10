#include<iostream>
using namespace std;
#define STACK_FULL 1
#define STACK_EMPTY 2

class Stack
{
    int top, capacity, *ptr;
    public:
        Stack(int);
        void push(int);
        int pop();
        bool stackOverflow();
        bool stackUnderflow();
        int size();
        void reverseStack(Stack &);
        void printStack();
        ~Stack();
};
 
Stack::Stack(int size)
{
    top = -1;
    capacity = size;
    ptr = new int[capacity];
}

Stack::~Stack()
{
    delete[] ptr;
}

bool Stack::stackOverflow()
{
    if(top == capacity-1)
        return true;
    return false;
}

bool Stack::stackUnderflow()
{
    if(top == -1)
        return true;
    return false;
}

void Stack::push(int item)
{
    if(stackOverflow())
        throw STACK_FULL;
    else
        ptr[++top] = item;
}

int Stack::pop()
{
    int t;
    if(stackUnderflow())
        cout << "Stack Empty" << endl;
    else
    {
        t = ptr[top];
        top--;
    }
    return t;
}

int Stack::size()
{
    return capacity;
}

void Stack::reverseStack(Stack &s)
{
    Stack s1(s.size()), s2(s.size());
    
    while(!s.stackUnderflow())
        s1.push(s.pop());
    
    while(!s1.stackUnderflow())
        s2.push(s1.pop());
    
    while(!s2.stackUnderflow())
        s.push(s2.pop());        
}

void Stack::printStack()
{
    int i;
    cout << endl
         << "After push operation the stack is: " << endl;

    for (i = 0; i <= top; i++)
        cout << ptr[i] << " ";
}

void trackMinimumElement(Stack &s)
{
    
}

int main()
{
    Stack s1(6);
    
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    s1.printStack();
    cout << endl
         << "Display Elements of stack: " << endl;

    s1.reverseStack(s1);
    s1.printStack();

    return 0;
}