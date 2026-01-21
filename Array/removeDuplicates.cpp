#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[5] = {1,3,3,45,5};
    int n = 5; //size of array
    int i=0;
    for (int j=1;j<n;j++)
    {
        if (A[i]!=A[j])
        {
            A[i+1]=A[j];
            i++;
        }
    }
}