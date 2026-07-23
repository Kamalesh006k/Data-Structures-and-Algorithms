#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> hash(256, 0);

        for (char x : t) {
            hash[x]++;
        }

        int l = 0, r = 0;
        int minlen = INT_MAX;
        int cnt = 0;
        int m = t.size();
        int strInd = -1;
        int n = s.size();

        while (r < n) {

            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            while (cnt == m) {

                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    strInd = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return (strInd == -1) ? "" : s.substr(strInd, minlen);
    }
};

int main() {
    string s, t;

    cout << "Enter string S: ";
    cin >> s;

    cout << "Enter string T: ";
    cin >> t;

    Solution obj;

    string ans = obj.minWindow(s, t);

    if (ans == "")
        cout << "No valid window found.\n";
    else
        cout << "Minimum Window Substring: " << ans << endl;

    return 0;
}