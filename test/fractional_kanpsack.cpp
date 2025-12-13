#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
    double x=1.0*a.second/a.first;
    double y=1.0*b.second/b.first;
    return x>y;
}
void kp(vector<pair<int,int>>vp,int c)
{
    sort(vp.begin(),vp.end(),compare);
    double ans=0;
    for(pair<int,int>x:vp)
    {   cout<<x.first<<" "<<x.second<<" "<<1.0*x.second/x.first<<endl;;
        if(c>x.first)
        {
            ans+=x.second;
            c-=x.first;
        }else
        {
            ans+=c*(1.0*x.second/x.first);
            c=0;
            break;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    vector<pair<int,int>>vp={{5,20},{20,40},{8,30},{10,84}};
   kp(vp,40);
}