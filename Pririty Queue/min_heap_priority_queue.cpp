#include<bits/stdc++.h>
using namespace std;


class MinHeap{
public:
 vector<int>heap;
 void heapifyDown(int i)
 {  
    int n=heap.size();
    int root=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n && heap[l]<heap[root])
    {
        root=l;
    }
    if(r<n && heap[r]<heap[root])
    {
        root=r;
    }
    if(root!=i)
    {
        swap(heap[i],heap[root]);
        heapifyDown(root);
    }
 }
 void heapifyUp(int i)
 {  
     if(i==0) return;
    int p=(i-1)/2;
    if(heap[p]>heap[i])
    {
        swap(heap[i],heap[p]);
        heapifyUp(p);
    }
 }
 void push(int x)
 {
    heap.push_back(x);
    heapifyUp(heap.size()-1);
 }
 void pop()
 {   
    if(heap.empty()) return;
    heap[0]=heap.back();
    heap.pop_back();
    heapifyDown(0);
 }
 int top()
 {
    return heap[0];
 }
 bool empty()
 {
     return heap.empty();
 }

};
int main()
{
    MinHeap pq;
    pq.push(4);
    pq.push(10);
    pq.push(2);
    pq.push(7);
    pq.push(1);

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}