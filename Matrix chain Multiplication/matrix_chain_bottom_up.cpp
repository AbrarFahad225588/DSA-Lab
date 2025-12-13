#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int p[]={2,3,4};
    int m[7][7]={0};
    int s[7][7]={0};
    int n=3;
    for(int d=1;d<n-1;d++)
    {
       for(int i=1;i<n-d;i++)
       {
         int j=i+d;
         int mn=INT_MAX;
         for(int k=i;k<=j-1;k++)
         {
            int q=m[i][k]+ m[k+1][j]+p[i-1]*p[k]*p[j];
            if(q<mn)
            {
                mn=q;
                s[i][j]=k;
            }
         }
         m[i][j]=mn;
       }
    }
    // cout<<m[1][n-1]<<" "<<s[1][n-1];
    for(int i=0;i<=n;i++)
    {
      for(int  j=0;j<=n;j++)
      {
        cout<<m[i][j]<<" ";
      }
      cout<<endl;
    }
}