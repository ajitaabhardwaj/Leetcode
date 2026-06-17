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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> ansthis;
        int flag = 0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr && flag == 0)
            {
                flag = 1;
                ans.push_back(ansthis);
                ansthis.clear();
                q.push(nullptr);
                continue;
            }

            if (node == nullptr && flag == 1)
            {
                break;
            }

            flag = 0;
            ansthis.push_back(node -> val);
            if (node -> left != nullptr)
                q.push(node -> left);
            if (node -> right != nullptr)
                q.push(node -> right);
                        
             
        }

        return ans;

    }
};