#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch,int freq)
    {
        this->ch=ch;
        this->freq=freq;
        left=right=NULL;
    }
};
class Comperator{
    public:
    bool operator()(Node *A,Node* B)
        {
            return A->freq > B->freq;
        }

};

Node* huffman(vector<char>ch,vector<int>freq)
{
    priority_queue<Node*,vector<Node*>,Comperator>pq;
    for(int i=0;i<ch.size();i++)
    {  
        Node* n=new Node(ch[i],freq[i]);
        pq.push(n);
    }
    while(pq.size()>1)
    {
        Node* x=pq.top();pq.pop();
        Node* y=pq.top();pq.pop();
          
        Node* z=new Node('#',x->freq+y->freq);
        z->left=x;
        z->right=y;
        pq.push(z);
     
    }
    return pq.top();
}
void printCodes(Node* root, string s) {
    if (!root) return;

    // If leaf node → print code
    if (!root->left && !root->right) {
        cout << root->ch << " : " << s << "\n";
    }

    printCodes(root->left, s + "0");
    printCodes(root->right, s + "1");
}
 int main() {
    vector<char> chars = {'A','B','C','D','E','F'};
    vector<int> freq = {5, 9, 12, 13, 16,45};
    Node * root=huffman(chars,freq);
    printCodes(root,"");
    return 0;
}