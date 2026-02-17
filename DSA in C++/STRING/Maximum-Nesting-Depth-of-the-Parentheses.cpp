#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxlen = 0;
        int openb = 0;

        for(char x : s) {
            if(x == '(') {
                openb++;                         // increase depth
                maxlen = max(maxlen, openb);     // update maximum
            }
            else if(x == ')') {
                openb--;                         // decrease depth
            }
        }
        return maxlen;
    }
};

int main() {
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    Solution obj;
    int result = obj.maxDepth(s);

    cout << "Maximum Nesting Depth: " << result << endl;

    return 0;
}
