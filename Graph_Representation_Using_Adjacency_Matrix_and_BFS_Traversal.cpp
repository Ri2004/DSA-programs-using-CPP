#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int capacity;
    int *arr;

    public:
        Queue(int);
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        ~Queue();
};

Queue ::Queue(int size)
{
    capacity = size;
    front = -1;
    rear = -1;
    arr = new int[capacity];
}

bool Queue ::isEmpty()
{
    return front == -1 && rear == -1;
}

void Queue :: enqueue(int item)
{
    if(isEmpty())
    {
        front++;
        arr[++rear] = item;
    }

    else
        arr[++rear] = item;
}

int Queue ::dequeue()
{
    int frontElement;

    if(isEmpty())
        return -1;
    
    else if(front == rear)
    {
        frontElement = arr[front];
        front = rear = -1;
    }

    else
        frontElement = arr[front++];
    
    return frontElement;
}

Queue ::~Queue()
{
    delete []arr;
}

class GraphMatrix
{
    int v_count;
    int e_count;
    int **adjMatrix;

    public:
        void createGraph(int, int);
        void printMatrix();
        void BFS(int);
        ~GraphMatrix();
};

void GraphMatrix ::createGraph(int vno, int eno)
{
    int v1, v2;

    v_count = vno;
    e_count = eno;
    adjMatrix = new int*[v_count];

    for(int i = 0; i < v_count; i++)
    {
        adjMatrix[i] = new int[v_count];

        for(int j = 0; j < v_count; j++)
            adjMatrix[i][j] = 0;
    }

    for(int i = 1; i <= e_count; i++)
    {
        cout << "Enter Vertices in between which an edge is present" << endl;
        cin >> v1 >> v2;

        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
}

void GraphMatrix ::printMatrix()
{
    for(int i = 0; i < v_count; i++)
    {
        for(int j = 0; j < v_count; j++)
            cout << adjMatrix[i][j] << " ";
        
        cout << endl;
    }
}

void GraphMatrix :: BFS(int strartingVertex)
{
    bool *visited = new bool[v_count];

    for(int i = 0; i < v_count; i++)
        visited[i] = false;
    
    Queue q(v_count);

    q.enqueue(strartingVertex);

    visited[strartingVertex] = true;

    for(int i = 0; i < v_count; i++)
    {
        int vertex = q.dequeue();
        cout << vertex << " ";

        for(int j = 0; j < v_count; j++)
        {
            if(adjMatrix[vertex][j] == 1 && !visited[j])
            {
                q.enqueue(j);
                visited[j] = true;
            }
        }
    }
}

GraphMatrix ::~GraphMatrix()
{
    for(int i = 0; i < v_count; i++)
        delete []adjMatrix[i];
    
    delete []adjMatrix;
}

int main()
{
    GraphMatrix gm;
    gm.createGraph(6, 7);
    gm.printMatrix();

    gm.BFS(0);

    cout << endl;
    return 0;
}