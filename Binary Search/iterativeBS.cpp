#include<bits/stdc++.h>
using namespace std;
int itrBS(vector<int>&A, int k)
{

    int s = 0;
    int e = A.size()-1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if (A[mid]==k) return mid;
        else if (A[mid]>k) {e=mid-1;}
        else s = mid+1;
    }
    return -1;
}
int main()
{
 vector<int> A = {2, 4, 6, 8, 10, 12};
    int k = 10;

    int index = itrBS(A, k);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}