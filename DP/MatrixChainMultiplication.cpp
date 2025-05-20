//Matrix Chain Multiplication		
//returns minimum multiplication operations to multiply n matrices
// [1,2,3,4,5] => n-1 matrices =>4
//    i     j     make partitions k from i to j

#include <bits/stdc++.h>
using namespace std;

//Recursion
int mcm(vector<int>& arr, int i, int j){
    if(i == j)
        return 0;
    int mini = INT_MAX;
    for(int k=i; k < j; k++){
        int ans=mcm(arr,i,k) + mcm(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini,ans); 
    }
    return mini;
}

//Memoization
int mcm(vector<int>& arr, int i, int j, vector<vector<int>>&dp){
    if(i == j)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = INT_MAX;
    for(int k=i; k < j; k++){
        int ans=mcm(arr,i,k,dp) + mcm(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini,ans);
    }
    return dp[i][j]=mini;
}

//Tabulation
int mcm(vector<int>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}
int main() {
	vector<int> arr = {10, 20, 30, 40, 50};
	int n=arr.size();
	cout<<mcm(arr,n);
	return 0;
}
