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
class Solution {
public:
    int check(TreeNode* root){
        if(!root) return 0;

        int left = check(root->left);
        int right = check(root->right);

        if(left == -1 or right ==-1) return -1;
        if(left == right or left == right+1){
            return 1+left;
        }
        if(left+1 == right){
            return 1+right;
        }
        else{
            return -1;
        }

     }
    bool isBalanced(TreeNode* root) {
        if(check(root) == -1) return false;
        else return true;
    }
};