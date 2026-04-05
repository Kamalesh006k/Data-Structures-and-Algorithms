#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        int k = 0, n = moves.size();

        while (k < n) {
            if (moves[k] == 'L') {
                j--;
            }
            else if (moves[k] == 'R') {
                j++;
            }
            else if (moves[k] == 'U') {
                i--;
            }
            else if (moves[k] == 'D') {
                i++;
            }
            k++;
        }

        if (i == 0 && j == 0)
            return true;
        return false;
    }
};

int main() {
    Solution obj;
    string moves;

    cout << "Enter the moves (L, R, U, D): ";
    cin >> moves;

    if (obj.judgeCircle(moves)) {
        cout << "Robot returns to origin (True)" << endl;
    } else {
        cout << "Robot does NOT return to origin (False)" << endl;
    }

    return 0;
}