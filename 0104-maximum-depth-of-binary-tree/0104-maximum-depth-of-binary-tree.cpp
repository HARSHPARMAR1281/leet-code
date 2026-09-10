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
    int dfs(TreeNode *root){
        if(root == NULL) return 0;

        int count_left = dfs(root->left);
        int count_right = dfs(root -> right);

        return 1 + max(count_left , count_right);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};