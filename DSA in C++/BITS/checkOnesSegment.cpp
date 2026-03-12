#include <bits/stdc++.h>
using namespace std;
// Check if Ones Segment is Present in the Binary String
class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '0' && s[i+1] == '1') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    
    if(obj.checkOnesSegment(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}