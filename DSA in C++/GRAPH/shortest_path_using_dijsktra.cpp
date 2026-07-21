// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    cin>>v;
    vector<vector<pair<int,int>>>adj(v);
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int st,en,wi;
        cin>>st>>en>>wi;
        adj[st].push_back({en,wi});
        adj[en].push_back({st,wi});
    }
    set<pair<int,int>>s;
    vector<int>dis(v,INT_MAX);
    vector<int>par(v);
    for(int i=0;i<v;i++)
    {
        par[i]=i;
    }
    int src;
    cin>>src;
    s.insert({0,src});
    dis[src]=0;
    while(!s.empty())
    {
        auto it=*(s.begin());
        auto dist=it.first;
        auto node=it.second;
        s.erase(s.begin());
        for(auto x : adj[node])
        {
            int adjn=x.first;
            int adist=x.second;
            if(dist+adist<dis[adjn])
            {
                if(dis[adjn]!=INT_MAX)
                {
                    s.erase({dis[adjn],adjn});
                }
                par[adjn]=node;
                dis[adjn]=dist+adist;
                s.insert({dis[adjn],adjn});
            }
        }
    }
    vector<int>res;
    int node=v-1;
    if(dis[node]==INT_MAX)
    {
        cout<<"No path";
        return 0;
    }
    while(par[node]!=node)
    {
        res.push_back(node);
        node=par[node];
    }
    res.push_back(node);
    reverse(res.begin(),res.end());
    for(auto x : res)
    cout<<x<<" ";
    
}