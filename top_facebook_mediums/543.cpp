/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node) {  
        if (node == NULL)  
            return 0;  
        else {  
            int lDepth = height(node->left);  
            int rDepth = height(node->right);  

            return max(lDepth, rDepth)+1;  
        }  
    } 
    int diameterOfBinaryTree(TreeNode* p) {
        if (p == NULL) {
            return 0;
        }
        int lheight = height(p -> left);
        int rheight = height(p -> right);
        int ldiametr = diameterOfBinaryTree(p -> left);
        int rdiametr = diameterOfBinaryTree(p -> right);
        int fd = max(lheight+rheight, max(ldiametr, rdiametr));
        return fd;
    }
};
