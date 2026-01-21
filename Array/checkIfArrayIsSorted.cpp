#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[5] = {1,2,3,45,5};
    int n = 5; //size of array
    for (int i=0;i<n;i++)
    {
        if (A[i-1]<=A[i])
        {cout<<"sorted";}
        else cout<<"not sorted";
    }
}