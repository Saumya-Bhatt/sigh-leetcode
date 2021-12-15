// preorder: <root><left><right>
// inorder: <left><root><right>

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

int searchIndexInInorder(vector<int>&inorder,int item){
    vector<int>::iterator it;
    it=find(inorder.begin(),inorder.end(),item);
    return it-inorder.begin();
}

TreeNode* helper(vector<int>&preorder,vector<int>inorder,int start,int end){
    static int preorder_index=0;
    TreeNode *node=new TreeNode(preorder[preorder_index]);
    preorder_index++;
    if(start==end)return node; // means we have reached a leaf node
    int index=searchIndexInInorder(inorder,node->val);
    node->left=helper(preorder,inorder,start,index-1);
    node->right=helper(preorder,inorder,index+1,end);
    return node;
}

TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
    return helper(preorder,inorder,0,preorder.size()-1);
}