#include <iostream>
#include <string>
using namespace std;
// Given a binary string s, return the number of steps to reduce it to 1 under the following rules:
class Solution {
public:
    int numSteps(string s) {
        int c = 0;
        
        while (s.size() > 1) {
            // If even → divide by 2
            if (s.back() == '0') {
                s.pop_back();
                c++;
                continue;
            }
            
            // If odd → add 1
            bool check = true;
            
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '0') {
                    s[i] = '1';
                    check = false;
                    break;
                }
                s[i] = '0';
            }
            
            // If all bits were 1 (like 111 → 1000)
            if (check)
                s = '1' + s;
            
            c++;
        }
        
        return c;
    }
};

int main() {
    string s;
    
    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;
    int result = obj.numSteps(s);

    cout << "Number of steps: " << result << endl;

    return 0;
}