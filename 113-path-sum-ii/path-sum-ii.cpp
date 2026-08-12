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
    void dfs(TreeNode* root, int target, int sum, vector<int> curr, vector<vector<int>>& ans){
        if(!root) return;

        sum = sum + root->val;
        curr.push_back(root->val);
        if(sum==target && !root->left && !root->right){
            ans.push_back(curr);
            return;
        }
       
        dfs(root->left, target, sum, curr, ans);
        dfs(root->right, target, sum, curr, ans);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;

        dfs(root, targetSum, 0, {}, ans );
        return ans;
        
    }
};