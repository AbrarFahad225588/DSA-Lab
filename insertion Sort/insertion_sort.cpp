#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int k=i-1;
        while(k>=0 && a[k]>key)
        {
            swap(a[k+1],a[k]);
            k--;
        }
        a[k+1]=key;
    }
}
int main()
{
    int a[]={7,2,4,5,3,0,7,2,5,4,8};
    insertion_sort(a,11);
    for(int i=0;i<11;i++)
    {
           cout<<a[i]<<" ";
    }
}