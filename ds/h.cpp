#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll tt;
  cin>>tt;

  while(tt--)
  {
      ll n,m;
      cin>>n>>m;
      set<ll>st;
      while(n--)
      {
          ll ne;
          cin>>ne;
          st.insert(ne);
      }


      while(m--)
      {
          ll x,y,z;

          cin>>x>>y>>z;
          st.insert(x);
           st.insert(y);
        st.insert(z);
      }
      cout<<st.size()<<endl;

  }

}
