#include<bits/stdc++.h>
using namespace std;

void merge(int l,int m,int r,int arr[])
{
    int nl=m-l+1;
    int nr=r-m;
    int L[nl],R[nr];

    for(int i=0;i<nl;i++) L[i]=arr[i+l];
    for(int i=0;i<nr;i++) R[i]=arr[m+1+i];

    int i=0,j=0,k=l;

    while(i<nl && j<nr)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }else
        {
            arr[k++]=R[j++];
        }
    }

    while(i<nl)
    {
        arr[k++]=L[i++];
    }
    while(j<nr)
    {
        arr[k++]=R[j++];
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