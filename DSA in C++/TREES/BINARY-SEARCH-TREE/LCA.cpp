#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *l, *r;

    node(int val)
    {
        this->val = val;
        l = r = NULL;
    }
};

node *root = NULL;

// Insert into BST
node* BuildTree(node *root, int val)
{
    if (root == NULL)
        return new node(val);

    if (val < root->val)
        root->l = BuildTree(root->l, val);
    else if (val > root->val)
        root->r = BuildTree(root->r, val);

    return root;
}

// Find LCA in BST
int lowest(node *root, int s, int e)
{
    if (root == NULL)
        return -1;

    // Ensure s <= e
    if (s > e)
        swap(s, e);

    if (s < root->val && e < root->val)
        return lowest(root->l, s, e);

    if (s > root->val && e > root->val)
        return lowest(root->r, s, e);

    return root->val;   // This is LCA
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        root = BuildTree(root, el);
    }

    int s, e;
    cin >> s >> e;

    cout << lowest(root, s, e);

    return 0;
}