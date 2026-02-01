#include<bits/stdc++.h>
using namespace std;
int firstOcc(vector<int> &A, int x)
{
    int first = -1;
    int s = 0;
    int e = A.size()-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if (A[mid]==x)
        {
            first=mid;
            e=mid-1;
        }
        else if (A[mid]<x)
        {
            s=mid+1;
        }
        else {e=mid-1;}
    }
    return first;
}
int lastOcc(vector<int> &A, int x)
{
    int last = -1;
    int s = 0;
    int e = A.size()-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if (A[mid]==x)
        {
            last=mid;
            s=mid+1;
        }
        else if (A[mid]<x)
        {
            s=mid+1;
        }
        else {e=mid-1;}
    }
    return last;
}
int lowerBound(vector<int> &nums, int x){
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int ans = n;
        while (s<=e)
        {
            int mid  = s+(e-s)/2;
            if (nums[mid]>=x) {ans=mid;
            e=mid-1;}
            else {s=mid+1;}
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int x){
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int ans = n;
        while (s<=e)
        {
            int mid  = s+(e-s)/2;
            if (nums[mid]>x) {ans=mid;
            e=mid-1;}
            else {s=mid+1;}
        }
        return ans;
    }
class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // int first = -1;
        // int last = -1;
        // for (int i=0;i<n;i++)
        // {
        //     if (nums[i]==target)
        //     {
        //         if (first == -1) first=i;
        //         last=i;
        //     }
        // }

        // int lb = lowerBound(nums,target);
        // int up = upperBound(nums,target);
        // if (lb == n || nums[lb]!=target) return {-1,-1};
        // return {lb,up-1};
        int f = firstOcc(nums,target);
        int l = lastOcc(nums,target);
        return {f,l};
    }
};