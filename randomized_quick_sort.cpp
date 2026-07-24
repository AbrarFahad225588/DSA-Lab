#include<bits/stdc++.h>
using namespace std;
int partition(int l,int r,int arr[])
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int randIndex(int l,int r,int arr[])
{
    int index=l+rand()%(r-l+1);
    swap(arr[r],arr[index]);
    return partition(l,r,arr);
}

void quickSortRandom(int l,int r,int arr[])
{
    if(l<r)
    {
        int p=randIndex(l,r,arr);
        quickSortRandom(l,p-1,arr);
        quickSortRandom(p+1,r,arr);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quickSortRandom(0,n-1,arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}