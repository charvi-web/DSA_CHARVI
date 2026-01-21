#include<bits/stdc++.h>
using namespace std;
void rotate(int* nums, int numsSize, int k) {
    int n=numsSize;
    int temp[n];
    // for (int i=n-k;i<n;i++)
    // {
    //     temp[i-(n-k)] = nums[i];
    // }

    // for (int i=0;i<n-k;i++)
    // {
    //     temp[i+k]=nums[i];
    // }
    // for (int i=0;i<n;i++)
    // {
    //     nums[i]=temp[i];
    // }
    for (int i=0;i<n;i++)
    {
        int index =(i+k)%n;
        temp[index]=nums[i];
    }
    for(int i=0;i<n;i++)
    {
        nums[i]=temp[i];
    }
}