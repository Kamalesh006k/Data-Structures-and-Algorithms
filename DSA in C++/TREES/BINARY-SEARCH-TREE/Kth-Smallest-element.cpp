#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Insert into BST
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
    void inorder(TreeNode* root, int& k, int& el) {
        if (root != NULL) {
            inorder(root->left, k, el);

            k--;
            if (k == 0) {
                el = root->val;
                return;
            }

            inorder(root->right, k, el);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int el = -1;
        inorder(root, k, el);
        return el;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    TreeNode* root = NULL;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    int ans = obj.kthSmallest(root, k);

    cout << "Kth smallest element: " << ans << endl;

    return 0;
}