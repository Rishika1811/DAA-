// Kruskal

#include <bits/stdc++.h>
using namespace std;

int find(int u,vector<int>&parent){
    if(u==parent[u]) return u;
    parent[u]= find(parent[u],parent);
    return parent[u];
}
void unionf(int u,int v,vector<int>&parent){
    int pu=find(u,parent),pv=find(v,parent);
    if(pu!=pv){
        parent[pv]=pu;
    }
}
vector<pair<int,pair<int,int>>> kruskals(vector<pair<int,pair<int,int>>> G,int E,int V){
    vector<pair<int,pair<int,int>>> sol;
    sort(G.begin(),G.end());
    vector<int>parent(V);
    for(int i=0;i<V;i++)
        parent[i]=i;
    for(int i=0;i<E;i++){
        int w=G[i].first,s=G[i].second.first,d=G[i].second.second;
        if(find(s,parent)!=find(d,parent)){
            sol.push_back(G[i]);
            unionf(s,d,parent);
        }
    }
    return sol;
}
int main() {
    // Graph: {weight, {start_vertex, end_vertex}}
    vector<pair<int, pair<int, int>>> G = {
        {10, {0, 1}}, {15, {0, 2}}, {5, {1, 2}}, {5, {2, 3}}, {10, {3, 4}}, {5, {1, 3}}, {20, {0, 4}}
    };

    int V = 5; 
    int E = G.size();  
    vector<pair<int, pair<int, int>>> mst = kruskals(G, E, V);

    // Print the MST
    for (auto edge : mst) {
        cout << edge.second.first << " -- " << edge.second.second << " (Weight: " << edge.first << ")\n";
    }
}

