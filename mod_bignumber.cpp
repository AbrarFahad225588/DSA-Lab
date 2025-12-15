#include<bits/stdc++.h>
using namespace std;
#define mod 1000000000
int mod_power(int a,int n)
{   
    if (n==1) return a;
   if(n%2==1)
   {
    int z=((a%mod)*(mod_power(a,n-1)%mod))%mod;
     return  z;
   }else
   {
      int test=mod_power(a,n/2)%mod;
      int z =(test*test)%mod;
      return z;
   }
}

int main()
{
    int a=10;
    int n=10;
    cout<<mod_power(a,n);
}