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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        
        // Create new root node
        if (depth - 1 == 0)
        {
            TreeNode* newAddedNodeAtRootPosition = new TreeNode(val);
            newAddedNodeAtRootPosition->left = root;
            return newAddedNodeAtRootPosition;
        }
        
        if (depth - 1 == 1)
        {
            TreeNode* newAddedNodeLeft = new TreeNode(val);
            TreeNode* newAddedNodeRight = new TreeNode(val);
            newAddedNodeLeft->left = root->left;
            newAddedNodeRight->right = root->right;
            root->left = newAddedNodeLeft;
            root->right = newAddedNodeRight;
            return root;
        }
        
        addOneRow(root->left, val, depth-1);
        addOneRow(root->right, val, depth-1);
        
        return root;
    }
};