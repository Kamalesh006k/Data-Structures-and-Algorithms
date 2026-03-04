#include<bits/stdc++.h>
using namespace std;

int findSecond(vector<int>& v, int n, int t, int i, int c)
{
    if(i >= n)
    {
        if(c == 0)
            return -1; // not found
        else
            return -2; // found only once
    }

    if(t == v[i])
    {
        c++;
        if(c == 2)
            return i;
    }

    return findSecond(v, n, t, i + 1, c);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int t;
    cin >> t;

    int res = findSecond(v, n, t, 0, 0);

    if(res != -1 && res != -2)
        cout << "The index of the second occurrence of the key value is: " << res;
    else if(res == -1)
        cout << "Key not found.";
    else
        cout << "Key found only once.";
}