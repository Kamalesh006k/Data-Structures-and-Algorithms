#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int maxLen = 1;
    int currLen = 1;

    for(int i = 1; i < n; i++)
    {
        if((arr[i] % 2 == 0 && arr[i-1] % 2 != 0) ||
           (arr[i] % 2 != 0 && arr[i-1] % 2 == 0))
        {
            currLen++;
            maxLen = max(maxLen, currLen);
        }
        else
        {
            currLen = 1;
        }
    }

    cout << maxLen;
}