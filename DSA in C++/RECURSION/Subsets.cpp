#include <bits/stdc++.h>
using namespace std;
//subsets
void subset1(vector<int>& v, int i, int n, vector<int>& ans, int sum)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }

    // include current element
    subset1(v, i + 1, n, ans, sum + v[i]);

    // exclude current element
    subset1(v, i + 1, n, ans, sum);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ans;
    subset1(v, 0, n, ans, 0);

    // REQUIRED by problem
    sort(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << " ";

    return 0;
}
