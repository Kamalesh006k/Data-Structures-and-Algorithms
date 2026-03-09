#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> it(n);

    for(int i=0;i<n;i++)
        cin >> it[i];

    sort(it.begin(),it.end());

    int m;
    cin >> m;

    vector<int> c(m);

    for(int i=0;i<m;i++)
        cin >> c[i];

    int serc = 0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(it[j] >= c[i])   // FIXED CONDITION
            {
                it[j] = it[j] - c[i];
                serc++;
                break;
            }
        }
    }

    cout << "Maximum number of customers served: " << serc;
}