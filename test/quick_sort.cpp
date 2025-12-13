#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l - 1;

    for(int j = l; j < h; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return i+1;
}
int randomized_partition(int a[], int l, int h)
{
    int randIndex = l + rand() % (h - l + 1); // random between l and h
    swap(a[randIndex], a[h]); // move random pivot to end
    return partition(a, l, h);
}

void quick_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int p=partition(a,l,h);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,h);

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