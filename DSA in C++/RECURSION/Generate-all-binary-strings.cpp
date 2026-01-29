// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void genrateString(int n,vector<string>&v,string &cur)
{
    if(cur.size()==n)
    {
        v.push_back(cur);
        return;
    }
    cur.push_back('0');
    genrateString(n,v,cur);
    cur.pop_back();
    if(cur.empty() || cur.back()!='1')
    {
    cur.push_back('1');
    genrateString(n,v,cur);
    cur.pop_back();
    }
    else
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<string>v;
    string d="";
    genrateString(n,v,d);
    for(auto x : v)
    cout<<x<<endl;
    

}