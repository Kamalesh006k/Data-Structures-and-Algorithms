// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool detectCycle(vector<bool>&vis,vector<int>head[],int st)
{
    queue<pair<int,int>>q;
    q.push({st,-1});
    vis[st]=true;
    while(!q.empty())
    {
        auto node=q.front().first;
        auto parent=q.front().second;
        q.pop();
    for(auto x : head[node])
    {
        if(!vis[x])
        {
            q.push({x,node});
            vis[x]=true;
        }
        else if(parent!=x)
        {
            return true;
        }
    }
    
    }
    return false;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>head[v];
    for(int i=0;i<e;i++)
    {
        int st,en;
        cin>>st>>en;
        head[st].push_back(en);
        head[en].push_back(st);
    }
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            if(detectCycle(vis,head,i))
            {
                cout<<"Cycle Detected";
                return 0;
            }
        }
    }
    cout<<"No Cycle Detected";
}