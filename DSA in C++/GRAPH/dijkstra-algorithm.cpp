class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(v);
        for(auto x : edges)
        {
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dis(v,INT_MAX);
        set<pair<int,int>>s;
        dis[src]=0;
        s.insert({0,src});
        while(!s.empty())
        {
            auto it=*(s.begin());
            auto node=it.second;
            auto dist=it.first;
            s.erase(s.begin());
            for(auto x : adj[node])
            {
                auto curdis=x.second;
                auto adnode=x.first;
                if(curdis+dist<dis[adnode])
                {
                    if(dis[adnode]!=INT_MAX)
                    {
                        s.erase({dis[adnode],adnode});
                    }
                    dis[adnode]=curdis+dist;
                    s.insert({dis[adnode],adnode});
                }
            }
        }
        return dis;
    }
    
};