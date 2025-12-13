#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<n && a[left]>a[largest])
    {
        largest=left; 
    }
    if(right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int a[]={1,5,3,34,6,5,89};
    int n=7;
    heapsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}