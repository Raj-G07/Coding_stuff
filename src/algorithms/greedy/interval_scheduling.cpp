// The Interval Scheduling problem is a Greedy Algorithm problem where the goal is to select the maximum number of non-overlapping intervals from a given set of intervals.

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
struct Interval {
    int start;
    int end;
};
bool intervalCompare(Interval a1, Interval a2) {
    return a1.end < a2.end;
}
int maxNonOverlappingIntervals(vector<Interval> intervals) {
    sort(intervals.begin(), intervals.end(), intervalCompare);

    int count = 1; // The first interval is always selected
    int lastEndTime = intervals[0].end;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= lastEndTime) {
            count++;
            lastEndTime = intervals[i].end;
        }
    }

    return count;
}