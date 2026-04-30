#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int n1 = nums1.size();
        // int n2 = nums2.size();
        // int n = n1 + n2;

        // int ind2 = n / 2;
        // int ind1 = ind2 - 1;
        // int ind1el = -1;
        // int ind2el = -1;
        // int i = 0;
        // int j = 0;
        // int cnt = 0;
        // while (i < n1 && j < n2) {
        //     if (nums1[i] < nums2[j]) {
        //         if (cnt == ind1)
        //             ind1el = nums1[i];
        //         if (cnt == ind2)
        //             ind2el = nums1[i];
        //         cnt++;
        //         i++;
        //     } else {
        //         if (cnt == ind1)
        //             ind1el = nums2[j];
        //         if (cnt == ind2)
        //             ind2el = nums2[j];
        //         cnt++;
        //         j++;
        //     }
        // }
        // while (i < n1) {
        //     if (cnt == ind1)
        //         ind1el = nums1[i];
        //     if (cnt == ind2)
        //         ind2el = nums1[i];
        //     cnt++;
        //     i++;
        // }
        // while (j < n2) {
        //     if (cnt == ind1)
        //         ind1el = nums2[j];
        //     if (cnt == ind2)
        //         ind2el = nums2[j];
        //     cnt++;
        //     j++;
        // }
        // if (n % 2 == 1)
        //     return (double)ind2el;
        // return (double)((double)(ind1el + ind2el) / 2.0);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int s =0;
        if (n1>n2) return  findMedianSortedArrays(nums2,nums1);
        int e = n1;
        int n = n1+n2;
        int left = (n1+n2+1)/2;
        while(s<=e)
        {
            int mid1 = (s+e)/2;
            int mid2 =  left-mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1<n1) r1 = nums1[mid1];
            if (mid2<n2) r2 = nums2[mid2];
            if (mid1-1>=0) l1 = nums1[mid1-1];
            if (mid2-1>=0) l2 = nums2[mid2-1];
            if (l1<=r2 && l2<=r1) {
                if(n%2==1) return max(l1,l2);
                return (double)((double)(max(l2,l1)+min(r1,r2))/2.0);
            }
            else if (l1>r2) e=mid1-1;
            else s=mid1+1;
        }
        return 0;
    }
};