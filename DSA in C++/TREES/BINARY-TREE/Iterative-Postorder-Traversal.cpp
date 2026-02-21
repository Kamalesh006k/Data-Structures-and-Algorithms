#include<bits/stdc++.h>
using namespace std;

/* Definition of Binary Tree Node */
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

/* Build Tree using Level Order Input */
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
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if(i < nodes.size())
        {
            TreeNode* leftNode = new TreeNode(nodes[i]);
            current->left = leftNode;
            q.push(leftNode);
            i++;
        }

        // Right child
        if(i < nodes.size())
        {
            TreeNode* rightNode = new TreeNode(nodes[i]);
            current->right = rightNode;
            q.push(rightNode);
            i++;
        }
    }

    return root;
}

/* Iterative Postorder Traversal (1 Stack) */
void postorder(TreeNode* root)
{
    if(root == NULL) return;

    stack<TreeNode*> st;
    TreeNode* cur = root;

    while(cur != NULL || !st.empty())
    {
        if(cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode* temp = st.top()->right;

            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->val << " ";

                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->val << " ";
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter node values (level order): ";
    for(int i = 0; i < n; i++)
        cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << "\nPostorder Traversal (Iterative - 1 Stack): ";
    postorder(root);

    return 0;
}