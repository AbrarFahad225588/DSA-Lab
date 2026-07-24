#include<bits/stdc++.h>
using namespace std;
struct Act{
 int s;
 int f;
};
bool cmp(Act a,Act b)
{
     return a.f<b.f;
}


void activity_selection(Act a[],int n)
{
    sort(a,a+n,cmp);
    cout<<a[0].s<<" "<<a[0].f<<endl;
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(a[i].f<a[j].s) 
        {
            cout<<a[j].s<<" "<<a[j].f<<endl;
            i=j;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    Act a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].s>>a[i].f;
    }
    activity_selection(a,n);
}