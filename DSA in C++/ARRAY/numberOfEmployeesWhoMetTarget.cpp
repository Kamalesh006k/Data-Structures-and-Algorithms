#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& h, int t) {
        int c = 0;
        for (auto x : h) {
            if (x >= t)
                c++;
        }
        return c;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int t;
    cin >> t;

    Solution obj;
    cout << obj.numberOfEmployeesWhoMetTarget(h, t);

    return 0;
}