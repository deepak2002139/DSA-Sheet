// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void solve(bool &flag,TreeNode* &p, TreeNode* &q)
//     {
//         if(p->val!=q->val)
//         {
//             flag =false;
//             return;
//         }
//         if(p->right==NULL&& q->right!=NULL||q->right==NULL&& p->right!=NULL)
//         {
//             flag=false;
//             return;
//         }
//         if(p->left==NULL&& q->left!=NULL||q->left==NULL&& p->left!=NULL)
//         {
//             flag=false;
//             return;
//         }
//         if(p->right==NULL &&p->left==NULL&& q->right==NULL && q->left==NULL)
//         {
//             return;
//         }
//         if(p->right!=NULL&&q->right!=NULL)
//             solve(flag,p->right,q->right);
//         if(p->left!=NULL&&q->left!=NULL)
//             solve(flag,p->left,q->left);
        
//     }
//     bool isSameTree(TreeNode* p, TreeNode* q)
//     {
//         if(p==NULL&&q==NULL)
//             return true;
//         bool flag=true;
//         solve(flag,p,q);
//         return flag;
//     }
// };
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
        // The below 3 If Else Statements checking 
        // if those 2 binary trees are structurally identical
        if(p==NULL && q==NULL) return true;
        else if(p!=NULL && q==NULL) return false;
        else if(p==NULL && q!=NULL) return false;
        
        // The below If Statement checking 
        // if those 2 binary trees have nodes with the same value
        if(p->val != q->val) return false;
        
        // Traversing Left
        bool left = isSameTree(p->left, q->left);
        // Traversing Right
        bool right = isSameTree(p->right, q->right);
        
        return left && right;
    }
};