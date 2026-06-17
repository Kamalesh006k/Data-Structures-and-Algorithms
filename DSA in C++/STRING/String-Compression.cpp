// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,res="";
    cin>>s;
    int c=1;
    for(int i=1;i<=s.size();i++)
    {
        if(i<s.size() && s[i-1]==s[i])
        {
            c++;
        }
        else
        {
            res+=s[i-1];
            res+=to_string(c);
            c=1;
        }
    }
    cout<<res;
}