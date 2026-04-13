#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& a, int t, int s) {
        int mini = INT_MAX;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == t) {
                mini = min(mini, abs(i - s));
            }
        }
        return mini;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target, start;
    cout << "Enter target: ";
    cin >> target;

    cout << "Enter start index: ";
    cin >> start;

    Solution obj;
    int result = obj.getMinDistance(nums, target, start);

    cout << "Minimum Distance: " << result << endl;

    return 0;
}