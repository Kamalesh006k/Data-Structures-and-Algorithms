#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//sort by bits in increasing order, if two numbers have same number of bits then sort by value
class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        
        sort(a.begin(), a.end(), [](int x, int y) {
            
            int c1 = __builtin_popcount(x);
            int c2 = __builtin_popcount(y);

            if (c1 == c2)
                return x < y;     // If bit count equal → smaller number first
            
            return c1 < c2;       // Sort by bit count
        });

        return a;
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.sortByBits(arr);

    cout << "Sorted by bits: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}