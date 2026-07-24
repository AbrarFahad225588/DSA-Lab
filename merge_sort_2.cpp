#include<bits/stdc++.h>
using namespace std;
void merge(int l,int m,int r,int a[])
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=a[i+l];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=a[i+m+1];
    }
   int i=0,j=0,k=l;
   while(i<n1 && j<n2)
   {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }else
        {
            a[k]=R[j];
            j++;
        }
        k++;
   }
   while(i<n1)
   {
    a[k]=L[i];
            i++;
            k++;
   }
   while(j<n2)
   {
    a[k]=R[j];
            j++;
            k++;
   }
}
void mergeSort(int l,int r , int arr[])
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(l,m,arr);
        mergeSort(m+1,r,arr);
        merge(l,m,r,arr);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(0,n-1,arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}