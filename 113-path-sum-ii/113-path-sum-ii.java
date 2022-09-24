/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// vector<vector<int>>& ans,vector<int>v,TreeNode* root, int& targetSum,int sum
class Solution 
{
     void solve(TreeNode root,int n ,List<Integer>list,List<List<Integer>>ans)
    {
        // if(root==null)
        //     return;
        //  list.add(root.val);
        //  sum+=root.val;
        //  if(root.left!=null &&root.right!=null && n==sum)
        //  {
        //      ans.add(list);
        //      return;
        //  }
        //  solve(ans,list,root.right,n,sum);
        //  solve(ans,list,root.left,n,sum);
         if (root == null)
         {
            return; 
        }
        list.add(root.val);
        if (root.left == null && root.right == null && root.val ==n)
        {
            ans.add(new ArrayList(list));
        }
         else
         {
            solve(root.left,n-root.val,list, ans);
            solve(root.right,n-root.val,list,ans);
        }
        list.remove(list.size()-1);
        
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) 
    {
        List<List<Integer>> ans = new ArrayList<List<Integer>>(); 
        List<Integer> list = new ArrayList<Integer>(); 
        // solve(ans,list,root,targetSum);
        solve(root,targetSum,list,ans);
        return ans;
    }
}
