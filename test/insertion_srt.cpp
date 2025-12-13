#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={1,5,3,34,6,5,89};
    int n=7;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}