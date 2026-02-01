#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int firstOcc(const vector<int>& A, int x)
{
    int first = -1;
    int s  = 0;
    int e = A.size()-1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if (A[mid]==x) {
            first = mid;
            e=mid-1;
        }
        else if (A[mid]<x)
        {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return first;
}
int lastOcc(const vector<int>& A, int x)
{
    int last = -1;
    int s  = 0;
    int e = A.size()-1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if (A[mid]==x) {
            last = mid;
            s=mid+1;
        }
        else if (A[mid]<x)
        {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return last;
}
    int countOccurrences(const vector<int>& arr, int target) {
        // Your code goes here
        int first = firstOcc(arr,target);
        int last = lastOcc(arr,target);
        if (first==-1) return 0;
        return last-first+1;
    }
};