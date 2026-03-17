#include<bits/stdc++.h>
using namespace std;

void dfs(int st, vector<bool>& vis, vector<vector<int>>& head)
{
    vis[st] = true;
    for(auto x : head[st])
    {
        if(!vis[x])
        {
            dfs(x, vis, head);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> head(v);
    vector<bool> vis(v, false);

    for(int i = 0; i < e; i++)
    {
        int st, en;
        cin >> st >> en;
        head[st].push_back(en);
        head[en].push_back(st);
    }

    int c = 0;

    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, head);
            c++;
        }
    }

    cout << c;
}