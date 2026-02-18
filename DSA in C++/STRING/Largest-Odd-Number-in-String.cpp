#include <bits/stdc++.h>
using namespace std;
// Problem: Largest Odd Number in String
class Solution {
public:
    string largestOddNumber(string s) {

        // Traverse from right to left
        for(int i = s.size() - 1; i >= 0; i--)
        {
            // Check if digit is odd
            if((s[i] - '0') % 2 == 1)
            {
                return s.substr(0, i + 1);
            }
        }

        return "";
    }
};

int main()
{
    string s;

    cout << "Enter a number string: ";
    cin >> s;

    Solution obj;
    string result = obj.largestOddNumber(s);

    if(result == "")
        cout << "No odd number substring found." << endl;
    else
        cout << "Largest odd number substring: " << result << endl;

    return 0;
}
