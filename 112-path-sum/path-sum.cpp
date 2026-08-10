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
    bool check(TreeNode* root, int target, int sum){
        if(!root) return false;
        sum = sum + root->val;

        if(sum == target && !root->left and !root->right){
            return true;
        }
        return ( check(root->left, target, sum) or check(root->right, target, sum));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0);
    }
};