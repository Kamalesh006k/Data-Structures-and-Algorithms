// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int pos,dis;
};
int main()
{
    
    vector<int>v(31,0);
    vector<bool>vis(31,false);
    for(int i=0;i<4;i++)
    {
        int s,e;
        cin>>s>>e;
        v[s]=e;
    }
    for(int i=0;i<4;i++)
    {
        int s,e;
        cin>>s>>e;
        v[s]=e;
    }
    queue<node>q;
    q.push({1,0});
    vis[1]=true;
    int result=-1;
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        if(x.pos==30){
            result=x.dis;
            break;
        }
        
        for(int dice=1;dice<=6;dice++)
        {
            int next=x.pos+dice;
            if(next<=30 && !vis[next])
            {
                vis[next]=true;
                if(v[next]!=0)
                {
                    next=v[next];
                }
                q.push({next,x.dis+1});
            }
        }
        
    }
    cout<<result;
}