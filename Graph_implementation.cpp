#include<iostream>
using namespace std;

class Graph
{
    int v_count, e_count, **adj;

public:
    void createGraph(int, int);
};

void Graph::createGraph(int vertices, int edges)
{
    v_count = vertices;
    e_count = edges;

    adj = new int *[v_count];
    
}

int main()
{
        
    return 0;
}