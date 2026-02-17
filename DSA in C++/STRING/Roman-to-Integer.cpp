#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> u;

        u['I'] = 1;
        u['V'] = 5;
        u['X'] = 10;
        u['L'] = 50;
        u['C'] = 100;
        u['D'] = 500;
        u['M'] = 1000;

        int n = u[s[s.length() - 1]];   // start from last character

        for(int i = s.length() - 2; i >= 0; i--) {
            if(u[s[i]] < u[s[i + 1]]) {
                n -= u[s[i]];
            }
            else {
                n += u[s[i]];
            }
        }

        return n;
    }
};

int main() {
    string s;

    cout << "Enter Roman numeral: ";
    cin >> s;

    Solution obj;
    int result = obj.romanToInt(s);

    cout << "Integer value: " << result << endl;

    return 0;
}
