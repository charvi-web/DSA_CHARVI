#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void inorder(Node* root, vector<int>& arr){
    if(!root) return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void preorderFill(Node* root, vector<int>& arr, int &i){
    if(!root) return;

    root->data = arr[i++];
    preorderFill(root->left, arr, i);
    preorderFill(root->right, arr, i);
}

void convertToMinHeap(Node* root){
    vector<int> arr;

    inorder(root, arr);

    int i = 0;
    preorderFill(root, arr, i);
}