#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
int activitySelection(vector<int> &start, vector<int> &finish)
{
    int ans = 0;
    vector<pair<int,int>> arr;

    for (int i = 0; i < start.size(); i++)
    {
        arr.push_back({start[i],finish[i]});
    }
    sort(arr.begin(), arr.end(),comp);
    int finishtime = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].first > finishtime)
        {
            finishtime = arr[i].second;
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    return 0;
}
