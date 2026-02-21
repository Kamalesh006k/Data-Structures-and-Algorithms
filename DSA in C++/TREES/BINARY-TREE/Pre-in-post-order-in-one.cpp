#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void preinpost(node * root)
{
    if(root == NULL) return;

    stack<pair<node*,int>> st;
    st.push({root,1});

    vector<int> pre, in, post;

    while(!st.empty())
    {
        auto x = st.top();
        st.pop();

        // Preorder
        if(x.second == 1)
        {
            pre.push_back(x.first->val);
            x.second++;
            st.push(x);

            if(x.first->left != NULL)
            {
                st.push({x.first->left,1});
            }
        }
        // Inorder
        else if(x.second == 2)
        {
            in.push_back(x.first->val);
            x.second++;
            st.push(x);

            if(x.first->right != NULL)
            {
                st.push({x.first->right,1});
            }
        }
        // Postorder
        else
        {
            post.push_back(x.first->val);
        }
    }

    // Printing results
    cout << "Preorder: ";
    for(int x : pre) cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for(int x : in) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for(int x : post) cout << x << " ";
    cout << endl;
}

int main()
{
    // Creating sample tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    preinpost(root);

    return 0;
}