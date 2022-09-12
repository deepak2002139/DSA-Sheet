class Solution
{
    private int greaterTree ( TreeNode root, int sum ) 
    {
        if ( root == null ) return 0;
        int rightSum = this.greaterTree(root.right, sum);
        int currVal = root.val;
        root.val = sum + rightSum + currVal;
        int leftSum = this.greaterTree(root.left, root.val);
        return currVal + rightSum + leftSum;
    }
    public TreeNode convertBST(TreeNode root) 
    {
        this.greaterTree(root, 0);
        return root;
    }
}