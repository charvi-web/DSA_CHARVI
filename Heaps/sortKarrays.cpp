#include <bits/stdc++.h> 
class node{
    public:
    int data;
    int i;
    int j ;
    node(int d,int row,int col)
    {
        data=d;
        i= row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b)
    {
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>,compare>minHeap;
    for (int i=0;i<k;i++)
    {
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
vector<int>ans;

    while( !minHeap.empty())
    {
        node* t = minHeap.top();
        ans.push_back(t->data);
        minHeap.pop();
        int r = t->i;
        int c = t->j;

        if (c+1<kArrays[r].size())
        {
            node* nn = new node(kArrays[r][c+1],r,c+1);
            minHeap.push(nn);
        }
    }
    return ans;
}

