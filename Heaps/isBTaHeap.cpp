#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
  int countNodes(Node* n)
  {
      if (n==NULL) return 0;
      return 1+countNodes(n->left)+countNodes(n->right);
  }
  bool isCBT(Node* tree,int c,int index)
  {
      if (tree==NULL) return true;
      if (index>=c) return false;
      return isCBT(tree->left,c,index*2+1) && 
      isCBT(tree->right,c,2*index+2); 
  }
  bool isMaxOrder(Node* tree)
  {
      if (tree->left==NULL && tree->right==NULL) return true;
      if (tree->right==NULL) return tree->data>tree->left->data;
      else return isMaxOrder(tree->left) && isMaxOrder(tree->right)&&
      tree->data>tree->left->data && 
      tree->data>tree->right->data;
  }
    bool isHeap(Node* tree) {
        if (tree==NULL) return true;
        int tcnt = countNodes(tree);
        return isCBT(tree,tcnt,0) && isMaxOrder(tree);
    }
};