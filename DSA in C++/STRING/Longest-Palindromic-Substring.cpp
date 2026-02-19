#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string isPalin(string s, int i, int j)
    {
        while(i >= 0 && j < s.length())
        {
            if(s[i] == s[j])
            {
                i--;
                j++;
            }
            else
                break;
        }
        
        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.length(); i++)
        {
            string odd = isPalin(s, i, i);       // odd length
            if(odd.size() > ans.size())
                ans = odd;

            string even = isPalin(s, i, i + 1);  // even length
            if(even.size() > ans.size())
                ans = even;
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.longestPalindrome(s);

    return 0;
}
