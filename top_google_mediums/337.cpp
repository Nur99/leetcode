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
    int rob(TreeNode* root) {
        int max_include_root = 0;
        int max_donot_include_root = 0;
        return houseRob(root,max_include_root,max_donot_include_root);
    }

    private:
    int houseRob(TreeNode* root, int &max_include_root, int &max_donot_include_root) {
   
        if(root == NULL) return 0 ;

        int max_include_left = 0,  max_include_right = 0;

        int max_donot_include_left = 0,  max_donot_include_right = 0;

        int max_left  =  houseRob(root->left  ,max_include_left,  max_donot_include_left) ;

        int max_right  =  houseRob(root->right,  max_include_right,  max_donot_include_right) ;

        max_include_root  =  root->val  +  max_donot_include_left  +  max_donot_include_right ;

        max_donot_include_root  =  max (max_include_left,  max_donot_include_left)  +  max (max_include_right,  max_donot_include_right) ;

        return max (max_include_root,  max_donot_include_root) ;
    }

};
