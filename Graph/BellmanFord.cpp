//Bellman Ford 
#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<pair<int,int>>>& G, int S) {
	vector<int> key(V, INT_MAX);
	vector<int> parent(V,-1);
	key[S] = 0;
	for(int i=0;i<V;i++){
    	for (int u = 0; u < V; u++) {
    		for (auto [v,weight] : G[u]) {                  
    			if (key[u] != INT_MAX && key[u] + weight < key[v]) {
    			    if(i==v) return {-1};           //check for -ve edge cycle
    				key[v] = key[u] + weight;
    				parent[v]=u;
				}
    		}
    	}
	}
	return key;
}
int main() {
	vector<vector<pair<int, int>>> G = {
        {{1,1}},{{2,3}},{{0,-5}}				//-ve edge cycle
    };
	int S = 0;
	vector<int> dist = bellman_ford(G.size(), G, S);
	for (auto d : dist) {
		cout << d << " ";
	}
}
