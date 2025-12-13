#include<bits/stdc++.h>
using namespace std;

 bool Comperator(pair<int ,int > a,pair<int,int> b)
 {
    return a.second<b.second;
 }

void activity_selection()
{
     vector<pair<int,int>> vp;
     vp={{1,5},{3,7},{5,6}};
     sort(vp.begin(),vp.end(),Comperator);
    
    
    int count=0;
    vector<pair<int,int>> ans;
    ans.push_back({vp[0].first,vp[0].second});
    for(int i=1;i<vp.size();i++)
    {
        if(vp[i-1].second<=vp[i].first)
        {
        count++;
        ans.push_back({vp[i].first,vp[i].second});
        }
    }

   cout<<count<<endl;
    for(pair<int ,int > x : ans)
     {
        cout<<x.first<<" "<<x.second<<endl;
     }

}
int main()
{
    activity_selection();
}