class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s = unordered_set<int>(begin(to_delete), end(to_delete));
        dfs(root);
        return ans;
    }

private:
    vector<TreeNode*> ans;
    unordered_set<int> s;

    void dfs(TreeNode *root, TreeNode *p = NULL){

        if(root == NULL){
            return;
        }

        if(root -> left){
            dfs(root -> left, root);
        }
        if(root -> right){
            dfs(root -> right, root);
        }

        if(s.find(root -> val) != s.end()){
            if(p != NULL){
                if(p -> left == root){
                    p -> left = NULL;
                }
                if(p -> right == root){
                    p -> right = NULL;
                }
            }

            if(root -> left != NULL){
                ans.push_back(root -> left);
            }
            if(root -> right != NULL){
                ans.push_back(root -> right);
            }
        }
        else if(p == NULL){
            ans.push_back(root);
        }
    }
};

