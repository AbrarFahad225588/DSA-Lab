#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& a,int n,int i)
{
    int root=i;
    int leftChild=i*2+1;
    int rightChild=2*i+2;
    if(n>leftChild && a[leftChild]>a[root])
    {
        root=leftChild;
    }
    if(n>rightChild && a[rightChild]>a[root])
    {
        root=rightChild;
    }
    if(root!=i)
    {
        swap(a[root],a[i]);
        heapify(a,n,root);
    }
}
void heap_sort(vector<int>& a,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}
int main()
{
    vector<int> v={1,5,8,3,9,4,2,8,4,3};
    heap_sort(v,v.size());
    for(int x:v)
    {
        cout<<x<<endl;
    }
}