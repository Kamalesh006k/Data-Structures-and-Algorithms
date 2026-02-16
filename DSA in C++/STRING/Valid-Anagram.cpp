#include <bits/stdc++.h>
using namespace std;
//valid Anagram: two strings are anagrams if they contain the same characters in the same frequency, but not necessarily in the same order.
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
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

    if(obj.isAnagram(s, t))
        cout << "The strings are Anagrams." << endl;
    else
        cout << "The strings are NOT Anagrams." << endl;

    return 0;
}
