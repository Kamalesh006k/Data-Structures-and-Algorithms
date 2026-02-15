#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for(int i = 0; i < s.size(); i++)
        {
            // Check mapping from s -> t
            if(st.count(s[i]) && st[s[i]] != t[i])
                return false;
            else
                st[s[i]] = t[i];

            // Check mapping from t -> s
            if(ts.count(t[i]) && ts[t[i]] != s[i])
                return false;
            else
                ts[t[i]] = s[i];
        }

        return true;
    }
};

int main()
{
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    Solution obj;

    if(obj.isIsomorphic(s, t))
        cout << "The strings are Isomorphic." << endl;
    else
        cout << "The strings are NOT Isomorphic." << endl;

    return 0;
}
