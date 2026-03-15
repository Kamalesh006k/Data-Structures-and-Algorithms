#include<bits/stdc++.h>
using namespace std;
// Maximum Path Sum in Binary Tree  
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
struct node
{
    int d;
    node *l,*r;
    node(int d)
    {
        this->d=d;
        this->l=NULL;
        this->r=NULL;
    }
};
node* build(vector<int>&v,int n,int &i)
{
    if(i>=n || v[i]==-1)
    {
        i++;
        return NULL;
    }
    node* root=new node(v[i++]);
    root->l=build(v,n,i);
    root->r=build(v,n,i);
    return root;
}
int maxpath(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftmax=max(0,maxpath(root->l,maxi));
    int rightmax=max(0,maxpath(root->r,maxi));
    maxi=max(maxi,leftmax+rightmax+root->d);
    return root->d+max(leftmax,rightmax);
}
int main()
{
    node* root=NULL;
    int n;
    vector<int>v;
    while(cin>>n)
    {
        v.push_back(n);
    }
    int i=0;
    root=build(v,v.size(),i);
    int maxi=INT_MIN;
    maxpath(root,maxi);
    cout<<"Maximum Path Sum "<<maxi;
}