#include<bits/stdc++.h>
using namespace std;
class MaxheapPriorityQueue{
    public:
 vector<int>a;
 void heapifyUp(int i)
 {  
    if(i==0) return;
    int p=(i-1)/2;
    if(a[i]>a[p])
    {
        swap(a[i],a[p]);
        heapifyUp(p);
    }
 }
 void heapifyDown(int i)
{   
    int n=a.size();
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
        heapifyDown(largest);
    }
}
void push(int x)
{
    a.push_back(x);
    heapifyUp(a.size()-1);
}
void pop()
{ 
    if(a.empty()) return ;
    
        a[0]=a.back();
        a.pop_back();
        heapifyDown(0);
}
int top()
{
     return a[0];
}
bool empty()
{
   return a.empty(); 
}
 
};
int main()
{
    MaxheapPriorityQueue pq;
    pq.push(5);
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(10);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}