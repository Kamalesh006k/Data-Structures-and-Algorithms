// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,vector<bool>&vis,vector<vector<int>>&head,int par)
{
    vis[i]=true;
    for(auto x : head[i])
    {
        if(!vis[x])
        {
            if(dfs(x,vis,head,i)) return true;
        }
        else if(x!=par)
        {
            return true;
        }
    }
    return false;
    
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>head(v);
    vector<bool>vis(v,false);
    for(int i=0;i<e;i++)
    {
        int st,en;
        cin>>st>>en;
        head[st].push_back(en);
        head[en].push_back(st);
    }
    for(int i=0;i<v;i++)
    {
        if(!vis[i]){
        if(dfs(i,vis,head,-1))
        {
            cout<<"Cycle detected";
            return 0;
        }
        }
    }
            cout<<"There is no Cycle detected";
}