#include <bits/stdc++.h>
using namespace std;
//problem: Sort Characters By Frequency
class Solution {
public:
    string frequencySort(string s) {
        
        // Step 1: Count frequency
        unordered_map<char,int> um;
        for(auto x : s) {
            um[x]++;
        }

        // Step 2: Max heap (frequency, character)
        priority_queue<pair<int,char>> pq;
        for(auto it : um) {
            pq.push({it.second, it.first});
        }

        // Step 3: Build answer
        string ans = "";
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            ans += string(top.first, top.second);
        }

        return ans;
    }
};

int main() {
    string s;
    
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    string result = obj.frequencySort(s);

    cout << "Sorted by frequency: " << result << endl;

    return 0;
}
