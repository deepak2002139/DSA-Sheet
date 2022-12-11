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
    long long ans = 0;
    long long solve(TreeNode* root,long long total){
        if(!root)
            return 0;
        long long subtreeSum1 = root->val+solve(root->left,total)+solve(root->right,total);
        long long subtreeSum2 = total - subtreeSum1;
        ans = max(ans,subtreeSum1 * subtreeSum2);
        
        return subtreeSum1;
    }
    long long solve(TreeNode* root){
        if(!root)
            return 0;
        
        return root->val+solve(root->left)+solve(root->right);
    }
    int maxProduct(TreeNode* root) {
        long long total = solve(root);
        solve(root,total);
        
        return (int)(ans % (int)(1e9 + 7));
    }
};