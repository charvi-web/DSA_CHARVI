#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[5] = {1,2,3,45,5};
    int n = 5; //size of array
    int largest = A[0];
    int secLargest = INT_MIN;
    int smallest = A[0];
    int secSmallest = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if (A[i]>largest)
        {
            secLargest = largest;
            largest=A[i];
            
        }
        if (A[i]>secLargest && A[i]<largest)
        {
            secLargest=A[i];
        }

        if (A[i]<smallest)
        {
            secSmallest = smallest;
            smallest = A[i];
        }

        if (A[i]!=smallest && A[i]<secSmallest)
        {
            secSmallest=A[i];
        }
    }
    cout<<smallest <<" " <<secSmallest <<" " << secLargest<< " "<< largest;

}