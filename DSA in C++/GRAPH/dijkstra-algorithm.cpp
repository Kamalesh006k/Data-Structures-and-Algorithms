#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V;
    cin >> V;

    int E;
    cin >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});      // Undirected graph
    }

    int src;
    cin >> src;

    vector<int> dis(V, INT_MAX);
    set<pair<int,int>> s;

    dis[src] = 0;
    s.insert({0, src});

    while(!s.empty())
    {
        auto it = *s.begin();

        int dist = it.first;
        int node = it.second;

        s.erase(s.begin());

        for(auto x : adj[node])
        {
            int adnode = x.first;
            int wt = x.second;

            if(dist + wt < dis[adnode])
            {
                if(dis[adnode] != INT_MAX)
                {
                    s.erase({dis[adnode], adnode});
                }

                dis[adnode] = dist + wt;
                s.insert({dis[adnode], adnode});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";

    for(int i = 0; i < V; i++)
    {
        if(dis[i] == INT_MAX)
            cout << "Node " << i << " : INF\n";
        else
            cout << "Node " << i << " : " << dis[i] << "\n";
    }

    return 0;
}