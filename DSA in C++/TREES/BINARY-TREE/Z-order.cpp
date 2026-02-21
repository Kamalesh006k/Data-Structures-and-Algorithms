#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build tree from level order input (-1 means NULL)
TreeNode* buildTree(vector<int> &arr) {
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag Level Order Function
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    q.push(root);
    int c = 0;

    while (!q.empty()) {
        int size = q.size();
        vector<int> res(size);

        for (int i = 0; i < size; i++) {
            TreeNode* x = q.front();
            q.pop();

            if (x->left != NULL)
                q.push(x->left);

            if (x->right != NULL)
                q.push(x->right);

            if (c == 0)
                res[i] = x->val;
            else
                res[size - i - 1] = x->val;
        }

        ans.push_back(res);
        c = (c == 0) ? 1 : 0;  // toggle direction
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print output
    for (auto level : result) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}