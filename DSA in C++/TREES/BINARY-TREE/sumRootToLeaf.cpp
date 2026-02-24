#include <iostream>
#include <queue>
using namespace std;

/* Definition for binary tree node */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void sum(TreeNode* root, int &ans, int cur)
    {
        if (!root)
            return;

        cur = cur * 2 + root->val;

        if (!root->left && !root->right)
        {
            ans += cur;
            return;
        }

        sum(root->left, ans, cur);
        sum(root->right, ans, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        sum(root, ans, 0);
        return ans;
    }
};

/* Function to build tree using level order */
TreeNode* buildTree()
{
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << temp->val << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1)
        {
            temp->left = new TreeNode(leftVal);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->val << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1)
        {
            temp->right = new TreeNode(rightVal);
            q.push(temp->right);
        }
    }

    return root;
}

int main()
{
    TreeNode* root = buildTree();

    Solution obj;
    int result = obj.sumRootToLeaf(root);

    cout << "Sum of Root to Leaf Binary Numbers: " << result << endl;

    return 0;
}