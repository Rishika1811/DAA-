#include <bits/stdc++.h>
using namespace std;

//Recursion
int fib(int n){
    if(n==0||n==1) return n;
    return fib(n-1)+fib(n-2);
}

//Memoization (Top-Down)
int fib(int n, vector<int>&dp){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

//Tabulation (Bottom-Up)
int fib(int n){
    if(n==0 || n==1) return n;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//Space optimization
int fib(int n){
    if(n==0 || n==1) return n;
    int prev2=0;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main()
{
    cout<<fib(5);
}
