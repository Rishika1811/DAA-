//Dijkstra’s algo             (same as prims with one line change)

#include <bits/stdc++.h>
using namespace std;

//here pq has{weight,vertex}, while adj list have {vertex,weight} 
void dijkstra(vector<vector<pair<int, int>>> G, int v,int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> key(v, INT_MAX);
    vector<bool> inMST(v, false);
    vector<int> parent(v, -1);

    key[source] = 0;
    pq.push({0, source}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        
        for (auto edge : G[u]) {				    //edge => pair<int,int> {vertex,weight} => edges connected to u
			int vertex = edge.first;
			int weight = edge.second; 
            if ( weight+key[u] < key[vertex]) {
                key[vertex] = weight+key[u];
                parent[vertex] = u;
                pq.push({key[vertex], vertex});
            }
        }
    }


    // OPTIONAL (skip)------------------------------------------------------------
// Print shortest distances and paths
    cout << "Shortest distances and paths from source " << ":\n";
    for (int i = 0; i < v; ++i) {
        cout << "To " << i << " (Distance: " << key[i] << "): ";
        // Path reconstruction
        stack<int> path;
        int node = i;
        while (node != -1) {
            path.push(node);
            node = parent[node];
        }
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<pair<int, int>>> G = {
    {{1,3}, {2,2}},           // 0
    {{0,3}, {2,3}, {3,3},{4,1}},    // 1
    {{0,2}, {1,3}, {4,4}},    // 2
    {{1,3}, {4,2}},           // 3
    {{2,4}, {3,2},{1,1}}            // 4
};
    int v = 5;
    int source = 4;

    dijkstra(G, v,source);
}
