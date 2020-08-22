class Solution {
public:
    string inorder(TreeNode* node, unordered_map<string, int>& m,vector<TreeNode*>& ans) 
    { 
        if (!node) 
            return ""; 

        string str = "("; 
        str += inorder(node->left, m, ans); 
        str += to_string(node->val); 
        str += inorder(node->right, m, ans); 
        str += ")"; 


        if (m[str] == 1) 
            ans.push_back(node); 

        m[str]++; 

        return str; 
    } 
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<string, int> m; 
        vector<TreeNode*>ans;
        inorder(root, m,ans);
        return ans;
    }
};
