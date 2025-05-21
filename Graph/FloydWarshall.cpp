//Floyd Warshall
#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix) {
	int n = matrix.size();
    for (int k = 0; k < n; k++) {
	    for (int i = 0; i < n; i++) {
	    	for (int j = 0; j < n; j++) {
				if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX){
			        if(matrix[i][j]> matrix[i][k]+matrix[k][j])
				        matrix[i][j]=matrix[i][k]+matrix[k][j];
			    }
			}
		}
	}
}
int main() {
	int V = 4;
	vector<vector<int>> matrix = {
       	{0, 3, INT_MAX, INT_MAX},
        {INT_MAX, 0, 1, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
		{10, INT_MAX, INT_MAX, 0}
    };
// 	vector<vector<int>> matrix(V, vector<int>(V, INT_MAX));
// 	matrix[0][1] = 2;
// 	matrix[1][0] = 1;
// 	matrix[1][2] = 3;
// 	matrix[3][0] = 3;
// 	matrix[3][1] = 5;
// 	matrix[3][2] = 4;
	
//  nodes distance to itself is 0 //very imp to initialize
// 	for(int i=0;i<V;i++){
// 	    matrix[i][i]=0;
// 	}
	shortest_distance(matrix);
	for (auto row : matrix) {
		for (auto cell : row) {
		    if(cell==INT_MAX)
		        cout<<"-1"<<" ";
		    else
			    cout << cell << " ";
		}
		cout << endl;
	}
}