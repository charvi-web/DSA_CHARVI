#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        // if (root==nullptr) {return ans;}
        // vector<int>lefti = inorderTraversal(root->left);
        // vector<int>righti = inorderTraversal(root->right);
        // ans.insert(ans.end(),lefti.begin(),lefti.end());
        // ans.push_back(root->val);
        // ans.insert(ans.end(),righti.begin(),righti.end());
        // return ans;
        TreeNode* cur = root;
        while (cur) 
        {
            if (cur->left==nullptr)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right!=cur) {
                    prev=prev->right;
                }
                if (prev->right==nullptr)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else {
                    prev->right=nullptr;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }

            }
        }
        return ans;
    }
    
}; 