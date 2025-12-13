#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
void activity_selector(vector<pair<int,int>> &vp)
{
    sort(vp.begin(),vp.end(),comparator);
    vector<pair<int,int>> ans;
   
    ans.push_back(vp[0]);
    for(int i=1;i<vp.size();i++)
    {
        if(vp[i-1].second<=vp[i].first)
        
            ans.push_back(vp[i]);
        
    }
    for(pair<int ,int> p:ans)
    {
        cout<<p.first<<" : "<<p.second<<endl;
    
    }
    cout<<ans.size()<<endl;
}
int main()
{
    vector<pair<int,int>>vp={{1,3},{2,3},{3,5},{6,7},{7,9},{9,11}};
    activity_selector(vp);
    return 0;
}