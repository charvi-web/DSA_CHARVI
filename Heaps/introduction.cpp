#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int A[100];
    int size;
    void insert(int val)
    {
        size=size+1;
        int index = size;
        A[index]=val;
        while (index>1)
        {
            int parent = index/2;
            if (A[parent]<A[index])
            {
                swap(A[index],A[parent]);
                index=parent;
            }
            else {return;}
        }
    }
};