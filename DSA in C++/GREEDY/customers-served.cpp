#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> it(n);
    for(int i=0;i<n;i++) cin>>it[i];

    int m;
    cin>>m;

    vector<int> c(m);
    for(int i=0;i<m;i++) cin>>c[i];

    sort(it.begin(),it.end());
    sort(c.begin(),c.end());

    int i=0,j=0,ans=0;

    while(i<n && j<m)
    {
        if(it[i] >= c[j])
        {
            ans++;
            i++;
            j++;
        }
        else
            i++;
    }

    cout<<"Maximum number of customers served: "<<ans;
}