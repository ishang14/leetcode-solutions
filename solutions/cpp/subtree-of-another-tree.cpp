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

    bool isIdentical(TreeNode* root1, TreeNode* root2){

        if(root1==NULL && root2==NULL)
        return true;

        if(root1==NULL || root2==NULL)
        return false;

        bool left=isIdentical(root1->left,root2->left);
        bool right=isIdentical(root1->right,root2->right);

        return left && right && root1->val==root2->val;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root==NULL && subRoot==NULL)
        return true;

        if(root==NULL || subRoot==NULL)
        return false;
        
        if(root->val==subRoot-> val && isIdentical(root,subRoot))
        return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};