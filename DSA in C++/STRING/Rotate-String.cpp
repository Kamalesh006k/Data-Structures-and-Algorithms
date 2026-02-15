#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};

int main()
{
    string s, goal;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    Solution obj;

    if(obj.rotateString(s, goal))
        cout << "Goal is a rotation of s." << endl;
    else
        cout << "Goal is NOT a rotation of s." << endl;

    return 0;
}
