#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& head, int st, vector<bool>& vis)
{
    vis[st] = true;
    for (auto x : head[st])
    {
        if (!vis[x])
        {
            dfs(head, x, vis);
        }
    }
}

int main()
{
    int n;
    cin >> n;  // number of cities

    vector<vector<int>> a(n, vector<int>(n));

    // Input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Convert matrix to adjacency list
    vector<vector<int>> head(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && i != j) // avoid self-loop
            {
                head[i].push_back(j);
            }
        }
    }

    // Count provinces
    vector<bool> vis(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(head, i, vis);
            count++;
        }
    }

    cout << count;

    return 0;
}