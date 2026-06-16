#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (auto x : s) {
            if (isalpha(x)) {
                res += x;
            }
            else if (x == '#') {
                res += res;
            }
            else if (x == '%') {
                reverse(res.begin(), res.end());
            }
            else {
                if (!res.empty())
                    res.pop_back();
            }
        }
        return res;
    }
};

int main() {
    Solution obj;

    string input;
    cout << "Enter the string: ";
    cin >> input;

    string result = obj.processStr(input);

    cout << "Processed string: " << result << endl;

    return 0;
}