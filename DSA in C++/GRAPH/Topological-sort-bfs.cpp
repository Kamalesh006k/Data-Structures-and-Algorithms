// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>head(v);
    vector<int>vis;
    vector<int>inde(v,0);
    for(int i=0;i<e;i++)
    {
        int st,en;
        cin>>st>>en;
        head[st].push_back(en);
    }
    queue<int>q;
    for(int i=0;i<v;i++){
    for(auto x : head[i])
    {
       inde[x]++;
    }
    }
    for(int i=0;i<v;i++)
    {
        if(inde[i]==0)
        q.push(i);
    }
    vector<int>res;
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        res.push_back(x);
        for(auto y : head[x])
        {
            inde[y]--;
            if(inde[y]==0)
            q.push(y);
        }
    }
    for(auto x : res)
    cout<<x<<" ";
}