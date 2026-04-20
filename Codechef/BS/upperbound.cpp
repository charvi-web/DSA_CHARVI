int upperBound(const vector<int>& nums, int x) {
    // write code here...
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int ans = n;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if (nums[mid]>x)
        {
            ans = mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return ans;
}