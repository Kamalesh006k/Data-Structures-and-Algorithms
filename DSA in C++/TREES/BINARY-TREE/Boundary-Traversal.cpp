// You are using GCC
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
bool isLeaf(node* root)
{
    if(root->l==NULL && root->r==NULL)
    {
        return true;
    }
    return false;
}

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
        if(i<n)
        {
            if(a[i]!=-1){
            node* right=new node(a[i]);
            x->r=right;
            q.push(right);
            }
        }
    }
    return root;
}
void addLeft(node * root,vector<int>&la)
{
    node* cur=root->l;
    while(cur)
    {
        if(!isLeaf(cur))
        la.push_back(cur->d);
        if(cur->l)
        cur=cur->l;
        else
        cur=cur->r;
    }
}
void addRight(node * root,stack<int>&a)
{
    node* cur=root->r;
    while(cur)
    {
        if(!isLeaf(cur))
         a.push(cur->d);
        if(cur->r)
        cur=cur->r;
        else
        cur=cur->l;
    }
}
void addLeaves(node * root,vector<int>&la)
{
    if(root==NULL) return ;
    
    if(isLeaf(root))
    {
        la.push_back(root->d);
        return ;
    }
    addLeaves(root->l,la);
    addLeaves(root->r,la);
   
}
void BoundaryTraversal(node* root,vector<int>&res)
{
    if(root==NULL)
    return ;
    if(!isLeaf(root))
    res.push_back(root->d);
    addLeft(root,res);
    addLeaves(root,res);
    stack<int>st;
    addRight(root,st);
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
}
int main()
{
    node* root=NULL;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    root=insert(a,n);
    vector<int>res;
    BoundaryTraversal(root,res);
    for(auto x : res)
    {
        cout<<x<<endl;
    }
}