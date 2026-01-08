#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSumOfGivenArray(vector<int>& nums) 
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for (int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        if (i>0 && nums[i]==nums[i-1])
        {
            continue;
        }
        while (j<k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if (sum>0)
            {
                k--;
            }
            else if (sum<0)
            {
                j++;;
            }
            else{
                vector<int>temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j<k && nums[j]==nums[j-1]) {j++;}
                while (j<k && nums[k]==nums[k+1]) {k--;}


            }
        }
    }
    return ans;
}
    
 
int main()
{
    int n ;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++)
        {cin>>nums[i];}
    vector<vector<int>> result = threeSumOfGivenArray(nums);
    cout<<"The triplets are: "<<endl;
    for ( auto& it : result) {
        cout << "[" << it[0] << ", " << it[1] << ", " << it[2] << "]" << endl;
    }

    return 0;
}