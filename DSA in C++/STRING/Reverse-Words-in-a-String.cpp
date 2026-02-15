#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string result = "";

        stringstream ss(s);

        // Extract words one by one
        while (ss >> word)
        {
            result = word + " " + result;
        }

        // Remove extra space at end
        if (!result.empty())
            result.pop_back();

        return result;
    }
};

int main()
{
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input);   // use getline for full sentence

    Solution obj;
    string output = obj.reverseWords(input);

    cout << "Reversed words: " << output << endl;

    return 0;
}
