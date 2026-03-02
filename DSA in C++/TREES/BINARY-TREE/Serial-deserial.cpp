// You are using GCC
#include<bits/stdc++.h>
using namespace std;

struct node
{
    string d;
    node *l,*r;
    node(string d)
    {
        this->d=d;
        this->l=NULL;
        this->r=NULL;
    }
};

node* insert(vector<string>&v,int n,int &i)
{
    if(i>=n || v[i]=="#")
    {
        i++;
        return NULL;
    }

    node* temp=new node(v[i++]);
    temp->l=insert(v,n,i);
    temp->r=insert(v,n,i);

    return temp;
}

void preorder(node* root,vector<string>&res)
{
    if(root==NULL)
    {
        res.push_back("#");
        return;
    }

    res.push_back(root->d);
    preorder(root->l,res);
    preorder(root->r,res);
}

int main()
{
    vector<string>v;
    string s;

    while(cin>>s)
        v.push_back(s);

    // Print input directly as Serialized tree
    cout<<"Serialized tree: ";
    for(auto x : v)
        cout<<x<<" ";

    // Build tree (Deserialize)
    int i=0;
    node* root=insert(v,v.size(),i);

    // Serialize again
    vector<string>res;
    preorder(root,res);

    cout<<"Deserialized tree: ";
    for(auto x : res)
        cout<<x<<" ";

    return 0;
}