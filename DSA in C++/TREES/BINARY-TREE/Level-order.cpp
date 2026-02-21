#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Node */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

/* Build Tree Using Your Logic (Level Order) */
TreeNode* buildTree(vector<int> &nodes)
{
    if(nodes.size() == 0)
        return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < nodes.size())
    {
        TreeNode* x = q.front();
        q.pop();

        // Left child
        if(i < nodes.size())
        {
            TreeNode* leftNode = new TreeNode(nodes[i]);
            x->left = leftNode;
            q.push(leftNode);
            i++;
        }

        // Right child
        if(i < nodes.size())
        {
            TreeNode* rightNode = new TreeNode(nodes[i]);
            x->right = rightNode;
            q.push(rightNode);
            i++;
        }
    }

    return root;
}

/* Level Order Traversal */
void levelOrder(TreeNode* root)
{
    if(root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int levelSize = q.size();

        for(int i = 0; i < levelSize; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter node values: ";
    for(int i = 0; i < n; i++)
        cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);

    return 0;
}