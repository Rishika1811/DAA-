//0/1 Knapsack
#include <bits/stdc++.h>
using namespace std;

//Recursion
int knapsack(int k, vector<int> &val, vector<int> &wt, int n) {
    if (n == 0 || k == 0)
        return 0;
    int pick = 0;
    if (wt[n - 1] <= k)
        pick = val[n - 1] + knapsack(k - wt[n - 1], val, wt, n - 1);
    int notPick = knapsack(k, val, wt, n - 1);
     
    return max(pick, notPick);
}

//Memoization
int knapsack(int k, vector<int> &val, vector<int> &wt, int n, vector<vector<int>>&dp) {
    if (n == 0 || k == 0)
        return 0;
    if(dp[n][k]!=-1) return dp[n][k];

    int pick = 0;
    if (wt[n - 1] <= k)
        pick = val[n - 1] + knapsack(k - wt[n - 1], val, wt, n - 1,dp);
    int notPick = knapsack(k, val, wt, n - 1,dp);
     
    return dp[n][k]=max(pick, notPick);
}

int main()
{
    vector<int> val = {1, 2, 3,5};
    vector<int> wt = {4, 5, 1,2};
    int k = 4;
    int n=val.size();
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    cout << knapsack(k, val, wt, val.size(),dp) << endl;
    return 0;
}

//Tabulation
int knapsack (vector<int>val, vector<int>wt,int k){
    int n=val.size();
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int pick = 0;
            if (wt[i - 1] <= j)
                pick = val[i - 1] + dp[i-1][j - wt[i - 1]];
            int notPick = dp[i-1][j];
            dp[i][j]=max(pick, notPick);
        }
    }
    return  dp[n][k] ;
}
