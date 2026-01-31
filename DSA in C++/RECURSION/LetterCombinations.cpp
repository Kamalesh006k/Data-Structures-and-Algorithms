#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void lCombinations(vector<string>& res,
                       int start,
                       unordered_map<char, string>& um,
                       string& d,
                       string& cur) {

        // ✅ base case
        if (cur.size() == d.size()) {
            res.push_back(cur);
            return;
        }

        string letters = um[d[start]];

        for (int i = 0; i < letters.size(); i++) {
            cur.push_back(letters[i]);
            lCombinations(res, start + 1, um, d, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string d) {
        vector<string> res;

        // ✅ edge case
        if (d.empty()) return res;

        unordered_map<char, string> um;
        um['2'] = "abc";
        um['3'] = "def";
        um['4'] = "ghi";
        um['5'] = "jkl";
        um['6'] = "mno";
        um['7'] = "pqrs";
        um['8'] = "tuv";
        um['9'] = "wxyz";

        string cur = "";
        lCombinations(res, 0, um, d, cur);
        return res;
    }
};

int main() {
    string digits;
    cin >> digits;

    Solution sol;
    vector<string> result = sol.letterCombinations(digits);

    for (string &s : result) {
        cout << s << " ";
    }

    return 0;
}
