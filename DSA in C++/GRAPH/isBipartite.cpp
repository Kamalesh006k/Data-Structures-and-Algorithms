#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& a, vector<int>& color, int i, int col) {
        color[i] = col;

        for (auto x : a[i]) {
            if (color[x] == -1) {
                if (!dfs(a, color, x, !col))
                    return false;
            }
            else if (color[x] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& a) {
        int v = a.size();
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!dfs(a, color, i, 0))
                    return false;
            }
        }

        return true;
    }
};

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V);

    cout << "Enter the adjacency list:\n";
    for (int i = 0; i < V; i++) {
        int n;
        cout << "Number of neighbors of vertex " << i << ": ";
        cin >> n;

        cout << "Enter the neighbors: ";
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    Solution obj;

    if (obj.isBipartite(graph))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is Not Bipartite\n";

    return 0;
}