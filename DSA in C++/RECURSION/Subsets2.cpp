#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void subsets2(vector<vector<int>>& ans, vector<int>& a,
                  vector<int>& v, int ind, int n)
    {
        ans.push_back(v);

        for (int i = ind; i < n; i++)
        {
            // skip duplicates at same recursion level
            if (i > ind && a[i] == a[i - 1])
                continue;

            v.push_back(a[i]);
            subsets2(ans, a, v, i + 1, n);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& a)
    {
        sort(a.begin(), a.end());   // IMPORTANT for duplicate handling
        vector<vector<int>> ans;
        vector<int> v;
        subsets2(ans, a, v, 0, a.size());
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements (may contain duplicates): ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solution obj;
    vector<vector<int>> result = obj.subsetsWithDup(a);

    cout << "\nSubsets are:\n";
    for (auto &subset : result)
    {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
