#include<bits/stdc++.h>
using namespace std;
int rodcutmemo(int n,int price[],int memo[])
{
    if(n==0) return 0;
    if(memo[n]!=-1) return memo[n];
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        m=max(m,price[i]+rodcutmemo(n-i-1,price,memo));
    }
    return memo[n]=m;
}

int main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    int memo[n+1];
    memset(memo,-1,sizeof(memo));
    cout<<rodcutmemo(n,price,memo)<<endl;
}

