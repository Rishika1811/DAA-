//Longest common subsequence (LCS)
#include <bits/stdc++.h>
using namespace std;

//Recursion
int lcs(string s1,string s2, int m,int n){
    if(m==0 || n==0) return 0;
    if(s1[m-1]==s2[n-1]) 
        return 1+lcs(s1,s2,m-1,n-1);
    return max( lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
}

//Memoization
int lcs(string s1,string s2, int m,int n,vector<vector<int>>&dp){              //dp[m+1][n+1]
    if(m==0 || n==0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m-1]==s2[n-1]) 
        dp[m][n]= 1+lcs(s1,s2,m-1,n-1,dp);
    else
        dp[m][n]=max( lcs(s1,s2,m-1,n,dp), lcs(s1,s2,m,n-1,dp));
    return dp[m][n];
}

//Tabulation
int lcs(string s1,string s2, int m,int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]) 
                dp[i][j]= 1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main() {
    string s1="bbaaa",s2="aaabb";
    int m=s1.size(),n=s2.size();

    cout << lcs(s1,s2,m,n);
}
