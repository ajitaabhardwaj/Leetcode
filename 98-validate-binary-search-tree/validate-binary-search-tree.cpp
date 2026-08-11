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
    

    bool dfs(TreeNode* node, long long int lbound, long long int rbound){
        if(!node) return true;

        if(node->val <= lbound or node->val >= rbound){
            return false;
        }
        return dfs(node->left, lbound, node->val) and dfs(node->right, node->val, rbound);
    }
    bool isValidBST(TreeNode* root) {
        long long int minl = -1* pow(2, 32);
        long long int maxr = pow(2, 32) -1;
        return dfs(root, minl, maxr);
    }
};