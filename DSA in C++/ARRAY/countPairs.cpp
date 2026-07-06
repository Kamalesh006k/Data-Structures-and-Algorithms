#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& a, int t) {
        int n = a.size();
        int c = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] < t) {
                    c++;
                }
            }
        }

        return c;
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    Solution obj;
    int ans = obj.countPairs(a, target);

    cout << "Number of pairs = " << ans << endl;

    return 0;
}