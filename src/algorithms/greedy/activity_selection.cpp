// You are given n activities with their start and end times. Select the maximum number of activities that can be performed by a single person, assuming that a person can work on only one activity at a time.

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

struct Activity {
    int start;
    int end;
};

bool activityCompare(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

int maxActivities(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), activityCompare);

    int count = 1; // The first activity is always selected
    int lastEndTime = activities[0].end;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEndTime) {
            count++;
            lastEndTime = activities[i].end;
        }
    }

    return count;
}
