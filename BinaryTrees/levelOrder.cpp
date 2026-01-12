#include<bits/stdc++.h>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<int>ans;
    //     if (root == nullptr) {
    //         return ans;
    //     }
    //     ans.push_back(root->val);
    //     vector<int>lefti = preorderTraversal(root->left);
    //     vector<int>righti = preorderTraversal(root->right);
    //     ans.insert(ans.end(),lefti.begin(),lefti.end());
    //     ans.insert(ans.end(),righti.begin(),righti.end());
    //    return ans;
vector<vector<int>>ans;
    queue<TreeNode*>q;
    if (root==nullptr) {return ans;}
    q.push(root);
    while (!q.empty())
    {
        vector<int>level;
    int size = q.size();
    for (int i=0;i<size;i++)
    {
        TreeNode* node = q.front();
        q.pop();
        level.push_back(node->val);
        if (node->left) {q.push(node->left);}
        if (node->right) {q.push(node->right);}
    }
    ans.push_back(level);
    }
    
    return ans;


    }
};