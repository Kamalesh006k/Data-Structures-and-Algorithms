// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct cell
{
    int pos;
    int dist;
};
int main()
{
    vector<int>move(31,0);
    vector<bool>vis(31,false);
    for(int i=0;i<4;i++)
    {
        int s,e;
        cin>>s>>e;
        move[s]=e;
    }
    for(int i=0;i<4;i++)
    {
        int s,e;
        cin>>s>>e;
        move[s]=e;
    }
    int res=-1;
    vis[1]=true;
    queue<cell>q;
    q.push({1,0});
    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();
        if(cur.pos==30)
        {
            res=cur.dist;
            break;
        }
        for(int dice=1;dice<=6;dice++)
        {
            int next=cur.pos+dice;
            if(next<=30 && vis[next]==false)
            {
                vis[next]=true;
                if(move[next]!=0)
                next=move[next];
                q.push({next,cur.dist+1});
            }
        }
    }
    cout<<"Min Dice throws required is "<<res;
    
}