class Solution {
public:
    int depth;
    void computeDepth(TreeNode* root){
        while(root){
            depth ++;
            root = root -> left;
        }
        return;
    }

    int check(TreeNode* root, int n){
        int k = depth - 1;
        vector<int> idx(depth, 0);
        int cur = n;
        while (n > 0){
            idx[k--] = n;
            n /= 2;
        }
        return exist(root, idx, 0);

    }
    int exist(TreeNode* root, vector<int>& idx, int d){
        if (d == depth - 1){
            return root != nullptr;
        }
        if (idx[d + 1] == idx[d] * 2)
            return exist(root -> left, idx, d + 1);
        return exist(root -> right, idx, d + 1);
    }
    int countNodes(TreeNode* root) {
        depth = 0;
        computeDepth(root);
        if (depth == 0)
            return 0;
        int base = 1 << (depth - 1) ;
        int l = base, r = (1 << depth) - 1;
        vector<int> idx(depth, 0);
        int mid = (l + r) / 2;

        while (l < r - 1){
            if (check(root, mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
            mid = (l+r) / 2;
        }
        for (int i = r; i >= l; i --){
            if (check(root, i))
                return i;
        }

        return 0;   
    }
};