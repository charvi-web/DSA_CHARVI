#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& A, int l, int mid, int h) {
        int cnt = 0;
        int right = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (right <= h && (long long)A[i] > 2LL * A[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    void merge(vector<int>& A, int l, int mid, int h) {
        vector<int> ans;
        int left = l;
        int right = mid + 1;

        while (left <= mid && right <= h) {
            if (A[left] <= A[right]) {
                ans.push_back(A[left]);
                left++;
            } else {
                ans.push_back(A[right]);
                right++;
            }
        }
        while (left <= mid) {
            ans.push_back(A[left]);
            left++;
        }
        while (right <= h) {
            ans.push_back(A[right]);
            right++;
        }
        for (int i = l; i <= h; i++)
            A[i] = ans[i - l];
    }
    int mergeSort(vector<int>& A, int l, int h) {
        int cnt = 0;
        if (l >= h)
            return 0;
        int mid = (l + h) / 2;
        cnt += mergeSort(A, l, mid);
        cnt += mergeSort(A, mid + 1, h);
        cnt += countPairs(A, l, mid, h);
        merge(A, l, mid, h);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};