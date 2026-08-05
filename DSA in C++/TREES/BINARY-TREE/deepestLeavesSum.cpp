#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int sum = 0;

        while (!q.empty()) {
            int n = q.size();
            sum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return sum;
    }
};

// Function to build tree from user input
TreeNode* buildTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << curr->val << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->val << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

int main() {
    TreeNode* root = buildTree();

    Solution obj;
    cout << "\nDeepest Leaves Sum = " << obj.deepestLeavesSum(root) << endl;

    return 0;
}