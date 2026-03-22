// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int d,k;
    node *prev,*next;
    node(int k,int d)
    {
        this->d=d;
        this->k=k;
        this->prev=NULL;
        this->next=NULL;
    }
    
};
class LRUCache
{
    public :unordered_map<int,node*>um;
    public :
    int n;
    public :
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    LRUCache(int n)
    {
        this->n=n;
        head->next=tail;
       tail->prev=head;
    }
     void addlink(node* temp)
     {
         temp->next=head->next;
         temp->prev=head;
         head->next->prev=temp;
         head->next=temp;
     }
     void deletenode(node *temp)
     {
         node *prevn=temp->prev;
         node *nextn=temp->next;
         prevn->next=nextn;
         nextn->prev=prevn;
     }
 
    void put(int k,int v)
    {
        if(um.find(k)==um.end())
        {
            node *temp=new node(k,v);
            if((int)um.size()<n)
            {
            addlink(temp);
            um[k]=temp;
            }
            else
            {
                node * cur=tail->prev;
                um.erase(cur->k);
                deletenode(cur);
                addlink(temp);
                um[k]=temp;
            }
            
        }
        else
        {
            node* temp=um[k];
            temp->d=v;
            deletenode(temp);
            addlink(temp);
        }
    }
    int get(int k)
    {
        if(um.find(k)==um.end())
        {
            return -1;
        }
        node * temp=um[k];
        deletenode(temp);
        addlink(temp);
        return temp->d;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    LRUCache ob(n);
    while(m--)
    {
        string s;
        cin>>s;
        if(s=="PUT")
        {
            int k,v;
            cin>>k>>v;
            ob.put(k,v);
        }
        else if(s=="GET")
        {
            int k;
            cin>>k;
            cout<<ob.get(k);
        }
    }
}