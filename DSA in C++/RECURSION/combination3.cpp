#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination3(vector<vector<int>>& ans,
                      vector<int>& res,
                      vector<int>& v,
                      int ind,
                      int k,
                      int t)
    {
        // ✅ valid combination
        if (res.size() == k && t == 0) {
            ans.push_back(res);
            return;
        }

        // ❌ invalid cases
        if (ind > 8 || res.size() > k || t < 0)
            return;

        // pick current number
        res.push_back(v[ind]);
        combination3(ans, res, v, ind + 1, k, t - v[ind]);
        res.pop_back();

        // not pick current number
        combination3(ans, res, v, ind + 1, k, t);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<int> v;

        // numbers from 1 to 9
        for (int i = 1; i <= 9; i++)
            v.push_back(i);

        combination3(ans, res, v, 0, k, n);
        return ans;
    }
};

int main() {
    int k, n;
    cin >> k >> n;

    Solution sol;
    vector<vector<int>> result = sol.combinationSum3(k, n);

    for (auto &comb : result) {
        cout << "[ ";
        for (int x : comb)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
