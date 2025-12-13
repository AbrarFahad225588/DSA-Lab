#include<bits./stdc++.h>
using namespace std;
class Node
{
public:
 char ch;
 int freq;
 Node *left,*right;
 Node(char ch,int freq)
 {
    this->ch=ch;
    this->freq=freq;
    left=right=NULL;
 }
};
class Comparator{
    public:
   bool operator()(Node* a,Node* b)
   {
     return a->freq>b->freq;
   }
};
Node* huffman(vector<char>& c,vector<int> & freqs)
{
    priority_queue<Node*,vector<Node*>,Comparator> pq;
    for(int i=0;i<c.size();i++)
    {
        Node* n=new Node(c[i],freqs[i]);
        pq.push(n);
    }
    while(pq.size()>1)
    {
        Node *x=pq.top();pq.pop();
        Node *y=pq.top();pq.pop();
        Node *n=new Node('#',x->freq+y->freq);
        n->left=x;
        n->right=y;
        pq.push(n);
    }
    return pq.top();
}
void print(Node *root,string cur)
{
    if(!root) return ;
    if(!root->left && !root->right)
    {
        cout<<root->ch<<"-"<<root->freq<<" : "<<cur<<endl;
    }
    print(root->left,cur+"0");
    print(root->right,cur+"1");
}
int main()
{
    vector<char>ch={'a','b','c','d','e'};
    vector<int>freq={150,20,45,65,23};
    Node* root=huffman(ch,freq);
    print(root,"");

}