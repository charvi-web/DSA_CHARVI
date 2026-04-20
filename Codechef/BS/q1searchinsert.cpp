
class Solution {
public:
    int searchInsertPosition(vector<int>& arr, int target) {
        // write your code here
        
        int n = arr.size();
        int ans = n;
        int s = 0;
        int e = n-1;
        while (s<=e)
        {
            int mid = s+(e-s)/2;
            if (arr[mid]>=target)
            {
                ans=mid;
                e=mid-1;
            }
            else {s=mid+1;}
        }
        return ans;
    }
};
