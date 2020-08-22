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
    int maxPath(TreeNode* root,int &res) {
        if (root == NULL) return 0;
        int l = maxPath(root->left, res);
        int r = maxPath(root->right, res);
        int maxrl = max(r, l);
        int maxone = max(maxrl+root->val, root->val);
        int maxall = max(maxone, l+r+root->val);
        res = max(res, maxall);
        return maxone;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPath(root,res);
        return res;
    }
};
