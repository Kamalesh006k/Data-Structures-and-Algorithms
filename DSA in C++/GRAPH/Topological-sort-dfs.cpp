// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<bool>&vis,vector<vector<int>>&head,int st,stack<int>&s)
{
    vis[st]=true;
    for(auto x : head[st])
    {
        if(!vis[x])
        {
            dfs(vis,head,x,s);
        }
    }
    s.push(st);
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
    }
    stack<int>st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        dfs(vis,head,i,st);
    }
    vector<int>res;
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    for(auto x : res)
    cout<<x<<" ";
}