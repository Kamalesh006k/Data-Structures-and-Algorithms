#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last  = strs[strs.size() - 1];

        string prefix = "";

        for(int i = 0; i < first.length() && i < last.length(); i++)
        {
            if(first[i] == last[i])
                prefix += first[i];
            else
                break;
        }

        return prefix;
    }
};

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter the strings:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    Solution obj;
    string result = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
