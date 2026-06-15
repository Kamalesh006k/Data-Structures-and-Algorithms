#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Insert into BST (for building tree easily)
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

class Solution {
public:
    bool Valid(TreeNode* root, long long minval, long long maxval) {
        if (root == NULL) return true;

        if (root->val <= minval || root->val >= maxval)
            return false;

        return Valid(root->left, minval, root->val) &&
               Valid(root->right, root->val, maxval);
    }

    bool isValidBST(TreeNode* root) {
        return Valid(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    TreeNode* root = NULL;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Valid BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}