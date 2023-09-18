#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int>> maxSumInterval(vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    return { maxSum, { start, end } };
}

int main() {
    vector<int> arr = {9,-3,1,7,-15,2,3,-4,2,-7,6,-2,8,4,-9};
    pair<int, pair<int, int>> result = maxSumInterval(arr);

    int maxSum = result.first;
    int startIndex = result.second.first;
    int endIndex = result.second.second;

    cout << "Maximum Sum: " << maxSum << endl;
    cout << "Interval: ";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
