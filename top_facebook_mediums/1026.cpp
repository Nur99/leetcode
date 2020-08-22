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
    int max_min(TreeNode *root,int maxm,int minm)
    {
        if(root==NULL) return abs(maxm-minm);
        maxm = max(maxm,root->val);
        minm = min(minm,root->val);
        return max(max_min(root->left,maxm,minm),max_min(root->right,maxm,minm));
    }
    int maxAncestorDiff(TreeNode* root) {
     return max_min(root,INT_MIN,INT_MAX);
    }
};
