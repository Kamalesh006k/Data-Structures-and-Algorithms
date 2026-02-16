#include <bits/stdc++.h>
using namespace std;
//Remove Outermost Parentheses: A primitive string is a non-empty string that cannot be partitioned into two non-empty valid parentheses strings. Given a valid parentheses string s, consider its primitive decomposition: s = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings. Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string result = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                int start = st.top();
                st.pop();

                // When stack becomes empty, one primitive is completed
                if(st.empty())
                    result += s.substr(start + 1, i - start - 1);
            }
        }

        return result;
    }
};

int main()
{
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    Solution obj;
    string answer = obj.removeOuterParentheses(s);

    cout << "Result after removing outer parentheses: " << answer << endl;

    return 0;
}
