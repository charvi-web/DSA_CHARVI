#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
int partition(vector<int>&nums,int low,int high)
{
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i<j)
    {
        while(i<=high-1 && nums[i]<=pivot )
        {i++;}
        while(j>=low+1 && nums[j]>pivot ) 
        {
            j--;
        }
        if (i<j) swap(nums[i],nums[j]);
    }
    swap(nums[low],nums[j]);
    return j;
}   
void quickSort(vector<int>&nums,int low,int high)
{
    if (low<high)
    {
        int pivotIndex = partition(nums,low,high);
        quickSort(nums,low,pivotIndex-1);
        quickSort(nums,pivotIndex+1,high);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};  