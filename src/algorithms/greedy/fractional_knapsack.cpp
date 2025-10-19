// The Fractional Knapsack Problem is a variation of the classic Knapsack Problem where you can take fractions of items rather than entire items. This makes the problem solvable using a Greedy Algorithm. 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

struct Item {
    int value;
    int weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item> items, int capacity) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto item : items) {
        if (capacity > 0 && item.weight > 0) {
            if (item.weight <= capacity) {
                totalValue += item.value;
                capacity -= item.weight;
            } else {
                totalValue += item.value * ((double)capacity / item.weight);
                capacity = 0;
            }
        }
    }

    return totalValue;
}
    