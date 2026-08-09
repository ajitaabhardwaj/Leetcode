/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode*p, TreeNode*q, TreeNode* &lca){
        if(!root) return false;
        bool curr = false;
        if(root == p || root == q){
            curr = true;
        };
        bool l = dfs(root->left, p, q, lca);
        bool r = dfs(root->right, p, q, lca);

        if(l and r) {
            lca = root;
            return true;
        }
        if( l and curr ) {
            lca = root;
            return true;
        }
        if( curr and r ) {
            lca = root;
            return true;
        }

        if(l or r or curr) {
            return true;
        }
       
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*lca = root;
        
        if( dfs(root, p, q, lca) == false) return root;
        
        return lca;

    }
};
