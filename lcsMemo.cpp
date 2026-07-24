#include<bits/stdc++.h>
using namespace std;
int LCS(string x,string y,int m,int n,int mm[][100])
{
    if(!m||!n) return 0;
    if(mm[m][n]!=-1) return mm[m][n];
    if(x[m-1]==y[n-1]) return mm[m][n]=1+LCS(x,y,m-1,n-1,mm);
    return mm[m][n]=max(LCS(x,y,m-1,n,mm),LCS(x,y,m,n-1,mm));
}

int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.size(),n=y.size();
    int mm[100][100];
    memset(mm,-1,sizeof(mm));
    cout<<LCS(x,y,m,n,mm)<<endl;
}