// The Minimum Platforms Problem is a classic Greedy Algorithm problem where the goal is to determine the minimum number of platforms required at a railway station so that no train is delayed due to a lack of platforms. 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int minPlatforms(vector<int> arrivals, vector<int> departures) {
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    int platformNeeded = 0;
    int maxPlatforms = 0;
    int i = 0, j = 0;
    int n = arrivals.size();

    while (i < n && j < n) {
        if (arrivals[i] <= departures[j]) {
            platformNeeded++;
            i++;
        } else {
            platformNeeded--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platformNeeded);
    }

    return maxPlatforms;
}