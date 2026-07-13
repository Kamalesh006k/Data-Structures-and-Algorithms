#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int st = 0, n = v.size(), maxlen = 0, zeros = 0;

        for (int en = 0; en < n; en++) {
            if (v[en] == 0)
                zeros++;

            if (zeros > k) {
                if (v[st] == 0)
                    zeros--;
                st++;
            }

            if (zeros <= k) {
                maxlen = max(maxlen, en - st + 1);
            }
        }

        return maxlen;
    }
};

int main() {
    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the binary array elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    cout << "Maximum consecutive 1s after flipping at most " << k
         << " zeros = " << obj.longestOnes(nums, k) << endl;

    return 0;
}