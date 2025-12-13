#include<bits/stdc++.h>
using namespace std;
int partitions(int a[],int l,int r)
{
    int i=l;
    int pivot=a[r];
    for(int j=l;j<r;j++)
    {  
        if(a[j]<pivot)
        {
           swap(a[i],a[j]);
            i++;
        }
        
    }
    swap(a[i],a[r]);
    return i;
}
int randomized_partition(int a[],int l,int r)
{
    int randIndex=l+rand()%(r-l+1);
    swap(a[randIndex],a[r]);
    return partitions(a,l,r);
}
void quick_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=randomized_partition(a,l,r);
        quick_sort(a,l,r-1);
        quick_sort(a,p+1,r);
    }
}
int main()
{
    int a[]={1,5,3,34,6,5,89};
    int n=7;
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}