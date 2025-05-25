//Subset Sum
#include <bits/stdc++.h>
using namespace std;

//Memoization
bool subsetSum(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) { 
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSum(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSum(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout<< subsetSum(n - 1, k, arr, dp);
}


//Tabulation
int main() {
    vector<int> arr = {2,3,4};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, false));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
        
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notTaken = dp[i-1][j];

            bool taken = false;
            if (arr[i] <= j)
                taken = dp[i-1][j-arr[i]];
        
            dp[i][j] = notTaken || taken;
        }
    }
    
    cout<< dp[n-1][k];
}
