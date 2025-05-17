// problem with profit and deadline //1 ≤ deadline[i] ≤ deadline.size()
#include<bits/stdc++.h>
using namespace std;
vector<int> jobScheduling(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    int cnt = 0, totProfit = 0;

    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }

    // sort the jobs based on profit in decreasing order
    sort(jobs.begin(), jobs.end(),greater<pair<int, int>>());

    // check time slot for job (we can take that job only if any slot before its deadline is available)
    vector<int> slot(n, 0);
    for (int i = 0; i < n; i++) {
        int start = min(n, jobs[i].second) - 1;
        for (int j = start; j >= 0; j--) {
            if (slot[j] == 0) {			// if any slot is empty take the job
                slot[j] = 1;
                cnt++;
                totProfit+= jobs[i].first;
                break;
            }
        }
    }
    
    return {cnt, totProfit};
}

int main() {
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobScheduling(deadline, profit);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
