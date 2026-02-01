// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int xaxis[]={0,-1,0,1};
int yaxis[]={-1,0,1,0};
bool isSafe(vector<vector<char>>&v,vector<vector<bool>>&vis,string t,int k,int i,int j,int n,int m)
{
    return i<n && j<m && i>=0 && j>=0 && k<t.size() && k>=0 && vis[i][j]==false && v[i][j]==t[k];
}
bool search(vector<vector<char>>&v,vector<vector<bool>>&vis,string t,int k,int i,int j,int n,int m)
{
    if(k==t.size()-1)
    {
        return true;
    }
    vis[i][j]=true;
    for(int l=0;l<4;l++)
    {
        int nexti=i+xaxis[l];
        int nextj=j+yaxis[l];
        if(isSafe(v,vis,t,k+1,nexti,nextj,n,m))
        {
            if(search(v,vis,t,k+1,nexti,nextj,n,m))
            return true;
        }
    }
    vis[i][j]=false;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    string t;
    cin>>t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==t[0] && vis[i][j]==false)
            {
              if(search(v,vis,t,0,i,j,n,m))
              {
                  cout<<"true";
                  return 0;
              }
                
            }
        }
    }
    cout<<"false";
}