#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int>&a,pair<int,int>&b){
    return (double)a.first/a.second>(double)b.first/b.second;
}
int fractionalKnapsack(vector<int>& val, vector<int>& wt, double k)
{
    vector<pair<int,int>> items;
    for (int i = 0; i < val.size(); i++)
    {
        items.push_back({val[i],wt[i]});
    }
    sort(items.begin(), items.end(),comp);
    double profit=0.0;
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].second<=k)
        {
            k-=items[i].second;
            profit+=items[i].first;
        }else{
            profit+= items[i].first*(k/items[i].second);		// k must be double 
            break;
        }
    }
    return profit;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    cout << fractionalKnapsack(val, wt, capacity) << endl;
}