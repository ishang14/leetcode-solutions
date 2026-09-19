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

    void helper(TreeNode* root,string path,vector<string>& ans){

        path = path + to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        path=path+"->";
        
        if(root->left)
        helper(root->left,path,ans);

        if(root->right)
        helper(root->right,path,ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path="";
        helper(root,path,ans);

        return ans;
    }
};