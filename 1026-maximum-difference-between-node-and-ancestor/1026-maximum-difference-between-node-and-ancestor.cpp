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
int maxAncestorDiff(TreeNode* root) {
  // Return 0 if the tree is empty.
  if (!root) return 0;

  // Store the maximum and minimum values seen so far.
  int max_diff = 0;

  // Helper function to traverse the tree and compute the maximum value of
  // |a.val - b.val| for all possible pairs of nodes (a, b) such that a is an
  // ancestor of b.
  function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int min_val, int max_val) {
    // Update the minimum and maximum values seen so far.
    min_val = min(min_val, node->val);
    max_val = max(max_val, node->val);

    // Update the maximum difference seen so far.
    max_diff = max(max_diff, max_val - min_val);

    // Recurse on the left and right subtrees.
    if (node->left) dfs(node->left, min_val, max_val);
    if (node->right) dfs(node->right, min_val, max_val);
  };

  // Traverse the tree using the helper function.
  dfs(root, root->val, root->val);

  // Return the maximum difference seen.
  return max_diff;
}
};