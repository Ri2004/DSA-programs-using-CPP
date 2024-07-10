#include <iostream>
using namespace std;

class GraphMatrix
{
    int v_count;
    int e_count;
    int **adjMatrix;

    public:
        void createGraph(int, int);
        void printMatrix();
        void DFS(int, bool* &);
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

    cout << "DFS Traversal Of Graph" << endl;
    bool* visited = new bool[v_count];

    for(int i = 0; i < v_count; i++)
        visited[i] = false;
    
    DFS(0, visited);

    printMatrix();
}

void GraphMatrix :: printMatrix()
{
    cout << "Adjacency Matrix Representation of Graph" << endl;

    for(int i = 0; i < v_count; i++)
    {
        for(int j = 0; j < v_count; j++)
            cout << adjMatrix[i][j] << " ";
        
        cout << endl;
    }
}

void GraphMatrix ::DFS(int startingVertex, bool* &visited)
{
    cout << startingVertex << " ";
    visited[startingVertex] = true;

    for(int i = 0; i < v_count; i++)
    {
        if(adjMatrix[startingVertex][i] && !visited[i])
            DFS(i, visited);
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
}