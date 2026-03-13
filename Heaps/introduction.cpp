#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int A[100];
    int size;
    Heap()
    {
        A[0]=-1;
        size=0;
    }
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
     void print()
        {
            for (int i=1;i<=size;i++)
            {
                cout<<A[i]<<" ";
            }
        }

    void deleteFromHeap()
    {
        if (size==0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }

        A[1]=A[size];
        size--;
        int i=1;
        while(i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if (leftIndex<size && A[i]<A[leftIndex])
            {
                swap(A[i],A[leftIndex]);
                i=leftIndex;
            }
            else if (rightIndex<size && A[i]<A[rightIndex])
            {
                swap(A[i],A[rightIndex]);
                i=rightIndex;
            }
            else {return;}
        }

    }

    void heapify(int A[],int n,int i)
    {
        int largest = i;
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;
        if (leftIndex<n && A[largest]<A[leftIndex])
        {
            largest=leftIndex;
        }
        if (rightIndex<n && A[largest]<A[rightIndex])
        {
            largest=rightIndex;
        }
        if (largest!=i)
        {
            swap(A[i],A[largest]);
            heapify(A,n,largest);
    }


    void heapSort(int A[],int n)
    {
        int size = n;
        while (size>1)
        {
            swap(A[1],A[size]);
            size--;
            heapify(A,n,1);
        }
    }
};
int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
}