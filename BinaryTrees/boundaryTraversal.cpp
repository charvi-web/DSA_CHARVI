#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isleaf(TreeNode* r)
{
    return (r != nullptr && r->left == nullptr && r->right == nullptr);
}

void leftTraversal(TreeNode* root, vector<int>& res)
{
    TreeNode* cur = root->left;
    while (cur)
    {
        if (!isleaf(cur))
            res.push_back(cur->data);

        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void rightTraversal(TreeNode* root, vector<int>& res)
{
    TreeNode* cur = root->right;
    vector<int> temp;

    while (cur)
    {
        if (!isleaf(cur))
            temp.push_back(cur->data);

        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

void addLeaves(TreeNode* root, vector<int>& res)  //preorder
{
    if (isleaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

class Solution {
public:
    vector<int> boundaryTrav(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) return res;

        // add root only if it is not a leaf
        if (!isleaf(root))
            res.push_back(root->data);

        leftTraversal(root, res);
        addLeaves(root, res);
        rightTraversal(root, res);

        return res;
    }
};
