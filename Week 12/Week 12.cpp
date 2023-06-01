#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> time(n, INT_MAX); // Initializing average time = infinity
    time[source] = 0; // Average times from source city to itself

    // Creating a min-heap priority queue to store cities and time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source); // Pushing source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second; // vertices with minimum weight(time)
        pq.pop();


        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0) {
                int weight = graph[u][v];

                // If the time to v through u is lesser, update the weight(time)
                if (time[u] + weight < time[v]) {
                    time[v] = time[u] + weight;
                    pq.emplace(time[v], v); // Pushing updated time(weight) to the priority queue
                }
            }
        }
    }

    return time;

}

int main() {
    //getting the adjacency matrix from the given graph
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };


    int source;
    cout << "Input source city -> "<<endl;
    vector<int> avgTime;
    cin >> source;  //getting the source city from user
    vector<int> time=dijkstra(graph, source); // initializing a time vector and making it equals dijkstra output vector
    for (int i = 0; i < time.size(); i++) {
        if (i != source) {
            cout << "Shortest time between City " << source << " to city " << i << " is " << time[i] << endl;
        } else
            continue;
    }

    return 0;
}