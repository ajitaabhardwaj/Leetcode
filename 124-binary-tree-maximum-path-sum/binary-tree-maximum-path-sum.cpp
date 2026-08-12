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

    int dfs(TreeNode* root, int& maxsum){
        if(!root) return 0;

        int leftsum = dfs(root->left, maxsum);
        int rightsum = dfs(root->right, maxsum);
        int sum1 = root->val + leftsum + rightsum;
        maxsum = max(maxsum, sum1);
        int sum = root->val + max(leftsum, rightsum);

        if(root->val< sum){
            maxsum = max(maxsum, sum);
            return sum;
        }
        else{
            maxsum = max(maxsum, root->val);
            return root->val;
        }
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = root->val;
        dfs(root, maxsum);
        return maxsum;
    }
};