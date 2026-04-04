#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string e, int r) {
        int size = e.size();
        
        if (r == 0) return "";
        
        int c = size / r;
        vector<vector<char>> v(r, vector<char>(c, ' '));

        int k = 0, alp = 0;

        // Fill matrix row-wise
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (k < size) {
                    v[i][j] = e[k++];
                    if (isalpha(v[i][j]))
                        alp++;
                } else break;
            }
        }

        int i = 0, j = 0, l = 1;
        string res = "";

        // Diagonal traversal
        while (i < r && j < c) {
            res += v[i][j];

            if (isalpha(v[i][j])) {
                alp--;
            }

            if (alp == 0) {
                break;
            }

            i++;
            j++;

            if (i == r && l < c) {
                i = 0;
                j = l;
                l++;
            }
        }

        return res;
    }
};

int main() {
    Solution obj;

    string encodedText;
    int rows;

    cout << "Enter encoded text: ";
    getline(cin, encodedText);   // to read spaces properly

    cout << "Enter number of rows: ";
    cin >> rows;

    string result = obj.decodeCiphertext(encodedText, rows);

    cout << "Decoded Text: " << result << endl;

    return 0;
}