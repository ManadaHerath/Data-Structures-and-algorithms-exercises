#include <bits/stdc++.h>
using namespace std;

#define V 6

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index; //initializing min value

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V]) //for printing the MST
{
    cout << "Edge     Weight"<<endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "   :   "
             << graph[i][parent[i]] << " \n";
}

void primAlgo(int graph[V][V])
{
    int parent[V];//to store the MST
    int key[V]; // to get the min weight edge in cut
    bool mstSet[V]; //vertices included or not in MST

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;//initializing all keys to infinite

    key[0] = 0; //making start vertex value to 0
    parent[0] = -1; //parent of start vertex is -1

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); //getting the minimum key vertex
        mstSet[u] = true; //uodating key value and parent index of the near vertex of picked vertexes
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph); //printing the made MST
}

int main()
{
    int graph[V][V] = { { 0, 3, 0, 0, 0,1 },
                        { 3, 0, 2, 1, 10,0 },
                        { 0, 2, 0, 3, 0,5 },
                        { 0, 1, 3, 0, 5,0 },
                        { 0, 10, 0, 5, 0,4 },
                        { 1,0,5,0,4,0} };

    primAlgo(graph);

    return 0;
}
