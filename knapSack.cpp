#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value;
    int weight;
};

int knapsack(vector<Item>& items, int capacity, vector<int>& selectedItems) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxValue = dp[n][capacity];

    // Trace back to find selected items
    int i = n, w = capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1); // Index of selected item
            w -= items[i - 1].weight;
        }
        i--;
    }

    reverse(selectedItems.begin(), selectedItems.end()); // Reverse to maintain original order

    return maxValue;
}

int main() {
    vector<Item> items = {{12, 2}, {10, 1}, {10, 3}, {15, 2}};
    int capacity = 5;

    vector<int> selectedItems;
    int maxValue = knapsack(items, capacity, selectedItems);

    cout << "Maximum value that can be obtained: " << maxValue << endl;
    cout << "Selected items:" << endl;
    for (int i : selectedItems) {
        cout << "Item " << i + 1 << ": Value = " << items[i].value << ", Weight = " << items[i].weight << endl;
    }

    return 0;
}
