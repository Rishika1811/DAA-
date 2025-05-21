// PRIMS
#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<pair<int, int>>> G, int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> key(v, INT_MAX);
    vector<bool> inMST(v, false);
    vector<int> parent(v, -1);

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto [vertex, weight] : G[u]) {
            if (!inMST[vertex] && weight < key[vertex]) {
                key[vertex] = weight;
                parent[vertex] = u;
                pq.push({weight, vertex});
            }
        }
    }

    // Print the MST
    cout << "Edges in MST:\n";
    for (int i = 1; i < v; ++i) {
        cout << parent[i] << " - " << i << " (weight = " << key[i] << ")\n";
    }

    // Calculate total cost
    int totalCost = 0;
    for (int i = 0; i < v; ++i) {
        totalCost += key[i];
    }
    cout << "Total cost of MST: " << totalCost << endl;
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
    prims(G, v);
}