// You are using GCC
#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Math
{
    public :
    t a,b;
    
    Math(t a,t b)
    {
        this->a=a;
        this->b=b;
    }
    
    t larger()
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    
};

int main()
{
  Math ab(10,20);
  cout<<ab.larger();
  
}