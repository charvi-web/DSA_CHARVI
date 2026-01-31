#include<bits/stdc++.h>
using namespace std;
int recrBS(vector<int>&A, int k,int start,int end)
{

    int mid = start+(end-start)/2;

    if (start>end) return -1;
    if (A[mid]==k) return mid;
    else if (A[mid]>k) {return recrBS(A,k,start,mid-1);}
    else {return recrBS(A,k,mid+1,end);}
    
}
int main()
{
 vector<int> A = {2, 4, 6, 8, 10, 12};
    int k = 10;

    cout<<"Element found at index : "<<recrBS(A,10,0,5);
    return 0;
}