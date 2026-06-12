// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n;
    cin>>n;
    unordered_set<string>um;
    for(int i=0;i<n;i++)
    {
        string el;
        cin>>el;
        um.insert(el);
    }
    queue<pair<string,int>>q;
    q.push({s,1});
    while(!q.empty())
    {
        auto node=q.front().first;
        auto steps=q.front().second;
        q.pop();
        auto original=node;
        if(node==t)
        {
            cout<<steps;
            return 0;
        }
        for(int i=0;i<node.size();i++)
        {
        for(char d='a';d<='z';d++)
        {
            node[i]=d;
            if(um.find(node)!=um.end())
            {
                um.erase(node);
                q.push({node,steps+1});
            }
        }
        node=original;
        }
    }
    cout<<0;
}