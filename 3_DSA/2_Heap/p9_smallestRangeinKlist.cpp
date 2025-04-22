#include <vector>
#include <queue>
#include <limits.h>
#include <utility> // for std::pair
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        int mini = INT_MAX; // Initialize to INT_MAX
        int maxi = INT_MIN; // Initialize to INT_MIN
        int k = a.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;

        // Initialize the heap with the first element of each list
        for (int i = 0; i < k; i++) {
            int element = a[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minheap.push({element, {i, 0}});
        }

        int start = mini, end = maxi;

        while (!minheap.empty()) {
            auto temp = minheap.top();
            minheap.pop();
            mini = temp.first; // The smallest element in the heap

            // Update the range if the current range is smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If there is a next element in the same row
            int row = temp.second.first;
            int col = temp.second.second;

            if (col + 1 < a[row].size()) {
                int nextElement = a[row][col + 1];
                maxi = max(maxi, nextElement);
                minheap.push({nextElement, {row, col + 1}});
            } else {
                break; // If there are no more elements in this row, we can stop
            }
        }

        return {start, end};
    }
};