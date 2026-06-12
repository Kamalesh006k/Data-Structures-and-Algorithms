#include<bits/stdc++.h>
using namespace std;

struct node
{
    int d;
    node* l,*r;
    node(int d)
    {
        this->d=d;
        this->l=NULL;
        this->r=NULL;
    }
};

node* insert(vector<int>&a,int n)
{
    node* root=new node(a[0]);
    queue<node*>q;
    q.push(root);
    for(int i=1;i<n;i++)
    {
        auto x=q.front();
        q.pop();

        if(a[i]!=-1)
        {
            node* left=new node(a[i]);
            x->l=left;
            q.push(left);
        }

        i++;
        if(i<n && a[i]!=-1)
        {
            node* right=new node(a[i]);
            x->r=right;
            q.push(right);
        }
    }
    return root;
}

bool Symmetric(node* Lroot, node* Rroot)
{
    if(Lroot==NULL && Rroot==NULL)
        return true;

    if(Lroot==NULL || Rroot==NULL)
        return false;

    if(Lroot->d != Rroot->d)
        return false;

    return Symmetric(Lroot->l, Rroot->r) &&
           Symmetric(Lroot->r, Rroot->l);
}

bool isSymmetric(node* root)
{
    if(root == NULL) return true;
    return Symmetric(root->l, root->r);
}

int main()
{
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    node* root = insert(a,n);

    cout << isSymmetric(root);

    return 0;
}