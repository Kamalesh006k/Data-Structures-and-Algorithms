#include<bits/stdc++.h>
using namespace std;
int dayInMonth(int m,int y)
{
    if(m==2)
    {
        if((y%400==0) || (y%4==0 && y%100!=0))
        {
            return 29;
        }
        return 28;
    }
    if(m==4 || m==6 || m==9 || m==11)
    return 30;
    return 31;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int d1=0,m1=0,y1=0,d2=0,m2=0,y2=0,i=0;
    while(a[i]!='-'  && b[i]!='-')
    {
        d1=10*d1+(a[i]-'0');
        d2=10*d2+(b[i]-'0');
        i++;
    }
    i++;
    while(a[i]!='-' && b[i]!='-')
    {
        m1=10*m1+(a[i]-'0');
        m2=10*m2+(b[i]-'0');
        i++;
    }
    i++;
    while(i<a.size() && i<b.size())
    {
        y1=10*y1+(a[i]-'0');
        y2=10*y2+(b[i]-'0');
        i++;
    }
    if(y1>y2 ||  (y1==y2 && m1> m2) || (y1==y2 && m1==m2 && d1> d2))
    {
             swap(y1,y2);
             swap(m1,m2);
             swap(d1,d2);
    }
    if(d2<d1)
    {
       m2--;
       if(m2==0)
       {
        m2=12;
        y2--;
       }
       d2+=dayInMonth(m2,y2);
    }
    if(m2<m1)
    {
        y2--;
        m2+=12;
    }
    cout<<d2-d1<<" Days "<<m2-m1<<" month "<<y2-y1<<" years";
}