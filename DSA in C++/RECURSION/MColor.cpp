// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int c,int start,vector<vector<int>>&head,vector<int>&res)
{
    for(auto x : head[start])
    {
        if(res[x]==c)
        return false;
    }
    return true;
}
void mcolor(int m,int start,vector<vector<int>>&head,vector<int>&res)
{
    if(start==head.size())
    {
    for(auto x : res)
    {
        cout<<x<<" ";
    }
        cout<<endl;
    return ;
    }
    for(int c=1;c<=m;c++)
    {
        if(isSafe(c,start,head,res))
        {
            res[start]=c;
             mcolor(m,start+1,head,res);
            res[start]=-1;
        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>head(v);
    for(int i=0;i<e;i++)
    {
        int st,en;
        cin>>st>>en;
        head[st].push_back(en);
        head[en].push_back(st);
    }
    int m;
    cin>>m;
    vector<int>res(v,-1);
    mcolor(m,0,head,res);
}