/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<algorithm>

class Solution {
public:
    TreeNode* build(int& i, int start, int end, vector<int>& preorder, unordered_map<int, int>& inorder){
        if(start>end || i>preorder.size()){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        int e = inorder[preorder[i]];
        i++;

        if(e-1 >= 0) {
           root->left  = build(i, start, e-1, preorder,inorder); 
        }

        if(e+1 < preorder.size()) {
           root->right = build(i, e+1, end, preorder,inorder);
           
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& ino) {
        int i=0;
        unordered_map<int, int> inorder;
        for(int x= 0; x<ino.size(); x++){
            inorder[ino[x]] = x;
        }
        return build(i, 0, preorder.size()-1, preorder, inorder);
    }
};