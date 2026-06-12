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

void rightSide(TreeNode* root,int level,vector<int>&ans)
{
        if(root==NULL)
        {
            return ;
        }
        if(level==(int)ans.size())
        {
            ans.push_back(root->val);
        }
        rightSide(root->right,level+1,ans);
        rightSide(root->left,level+1,ans);
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
    rightSide(root,0,res);
    for(auto x : res)
    {
        cout<<x<<endl;
    }
}