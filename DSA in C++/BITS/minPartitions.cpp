#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int big = INT_MIN;
        
        for (auto x : n) {
            int res = x - '0';
            if (res > big)
                big = res;
        }
        
        return big;
    }
};

int main() {
    string n;
    
    cout << "Enter number: ";
    cin >> n;

    Solution obj;
    int result = obj.minPartitions(n);

    cout << "Minimum number of deci-binary numbers required: " << result << endl;

    return 0;
}