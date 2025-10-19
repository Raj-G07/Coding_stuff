// The Job Sequencing Problem is a classic Greedy Algorithm problem where you aim to maximize the profit by scheduling jobs within a given deadline.

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool jobCompare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, vector<int>> jobScheduling(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end(), jobCompare);
    int maxDeadline = 0; 
    for (const auto &job : jobs) { 
       maxDeadline = max(maxDeadline, job.deadline); 
      } 
    int n = jobs.size();
    vector<int> result(maxDeadline, -1);
    vector<int> scheduledJobs;
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (result[j]==-1) {
                result[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                scheduledJobs.push_back(jobs[i].id);
                break;
            }
        }
    }

    return {maxProfit, scheduledJobs};
}
