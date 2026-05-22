// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int xaxis[4]={0,-1,0,1};
int yaxis[4]={-1,0,1,0};
bool isSafe( vector<vector<int>>&v, vector<vector<bool>>&vis,int i,int j,int n,int m)
{
    return i<n && j<m && i>=0 && j>=0 && v[i][j]==1 && vis[i][j]==false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    vector<vector<bool>>vis(n,vector<bool>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    queue<pair<int,int>>q;
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==1 && !vis[i][j])
            {
                    c++;
                q.push({i,j});
                vis[i][j]=true;
                while(!q.empty())
                {
                    
                    auto x=q.front();
                    q.pop();
                    for(int s=0;s<4;s++)
                    {
                        int nextx=x.first+xaxis[s];
                        int nexty=x.second+yaxis[s];
                        if(isSafe(v,vis,nextx,nexty,n,m))
                        {
                            vis[nextx][nexty]=true;
                            q.push({nextx,nexty});
                        }
                    }
                }
            }
        }
    }
    cout<<c;
}