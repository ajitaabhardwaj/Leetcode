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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if (root) q.push(root);
        else return ans;

        while(!q.empty()){
            int sz = q.size();
            vector<int>a;
            for(int i=0; i<sz; i++){
                
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                a.push_back(temp->val);
            }
            if(ans.size()%2 == 1) reverse(a.begin(), a.end());
            ans.push_back(a);
        }
        return ans; 
    }
};