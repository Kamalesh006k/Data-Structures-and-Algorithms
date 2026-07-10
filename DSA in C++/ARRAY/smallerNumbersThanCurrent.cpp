#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int n = a.size();
        vector<int> res(a.size(), 0);

        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && a[j] < a[i])
                    c++;
            }
            res[i] = c;
        }
        return res;
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution obj;
    vector<int> ans = obj.smallerNumbersThanCurrent(a);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}