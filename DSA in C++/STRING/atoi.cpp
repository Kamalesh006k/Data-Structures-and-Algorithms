#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int i = 0, l = s.length();

        // 1. Skip leading spaces
        while(i < l && isspace(s[i])) {
            i++;
        }

        if(i == l) return 0;  // safety check

        // 2. Handle sign
        bool negative = false;

        if(s[i] == '-') {
            negative = true;
            i++;
        }
        else if(s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        int val = 0;

        while(i < l && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Overflow check
            if(val > INT_MAX / 10 ||
               (val == INT_MAX / 10 && digit > 7)) {
                return negative ? INT_MIN : INT_MAX;
            }

            val = val * 10 + digit;
            i++;
        }

        return negative ? -val : val;
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    getline(cin, s);

    Solution obj;
    int result = obj.myAtoi(s);

    cout << "Converted integer: " << result << endl;

    return 0;
}
