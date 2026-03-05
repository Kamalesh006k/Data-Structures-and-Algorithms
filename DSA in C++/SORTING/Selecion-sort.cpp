#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << "Students' height order before sorting:" << endl;
    for(int x : v)
        cout << x << " ";
    cout << endl;

    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for(int j = i+1; j < n; j++)
        {
            if(v[j] < v[minIndex])
                minIndex = j;
        }

        swap(v[i], v[minIndex]);

        cout << "At the end of iteration " << i+1 << ":" << endl;
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }

    cout << "After sorting, the height order is:" << endl;
    for(int x : v)
        cout << x << " ";
}