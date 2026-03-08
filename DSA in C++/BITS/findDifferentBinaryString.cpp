#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    string result = obj.findDifferentBinaryString(nums);

    cout << result << endl;

    return 0;
}