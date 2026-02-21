#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build tree from level order input
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

// Check if trees are same
bool isSameTree(TreeNode* p, TreeNode* q) {

    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {

    int n1, n2;
    cin >> n1;

    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    cin >> n2;

    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    TreeNode* root1 = buildTree(arr1);
    TreeNode* root2 = buildTree(arr2);

    if (isSameTree(root1, root2))
        cout << "Trees are identical";
    else
        cout << "Trees are NOT identical";

    return 0;
}