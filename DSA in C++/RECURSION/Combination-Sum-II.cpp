#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Combination(int n,
                     vector<int>& res,
                     vector<vector<int>>& ans,
                     int t,
                     int ind,
                     vector<int>& v)
    {
        if (t == 0) {
            ans.push_back(res);
            return;
        }

        for (int i = ind; i < n; i++) {
            // Skip duplicates
            if (i > ind && v[i] == v[i - 1])
                continue;

            // Pruning
            if (v[i] > t)
                break;

            res.push_back(v[i]);
            Combination(n, res, ans, t - v[i], i + 1, v);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> res;

        Combination(candidates.size(), res, ans, target, 0, candidates);
        return ans;
    }
};

int main() {
    Solution sol;

    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Combinations are:\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
