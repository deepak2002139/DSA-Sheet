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
    void solve(TreeNode* node, vector<int>&ans)
    {
        ans.push_back(node->val);
        if(node->left!=NULL)
        {
            solve(node->left,ans);
        }
        if(node->right!=NULL)
        {
            solve(node->right,ans);
        }
    }
        
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)
            return ans;
        solve(root,ans);
        return ans;
    }
};