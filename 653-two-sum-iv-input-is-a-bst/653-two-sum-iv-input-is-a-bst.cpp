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
class Solution 
{
    unordered_map<int,int> mp;
    bool ans = false;
public:
    void solve(TreeNode* node,int k)
    {
       
        if(node==NULL) 
            return;
        if(mp[k-node->val]==1) 
        {
            ans = true;
            return;
        }
        else mp[node->val]=1;
        
        solve(node->left,k);
        solve(node->right,k);
    }
    bool findTarget(TreeNode* root, int k)
    {
        solve(root, k);
        return ans;
    }
};