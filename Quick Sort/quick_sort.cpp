#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int h)
{ 
    // for(int i=l;i<=h;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int pivot=a[l];
    int i=l,j=h;
    while(i<j){
    while(a[i]<=pivot){
        i++;
    }
    while(a[j]>pivot){
        j--;
    }
    if(i<j)
    {
        swap(a[i],a[j]);
    }
}
    swap(a[l],a[j]);
    return j;
}
void quick_sort(int a[],int l,int h)
{  
    if(l>=h) return;
    int p=partition(a,l,h);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,h);

}
int main()
{
    int a[]={1,4,6,5,3,2};
    quick_sort(a,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }
}