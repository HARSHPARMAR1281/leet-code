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
    int maxi = -1;
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        
        int count_left = dfs(root -> left);
        int count_right = dfs(root -> right);
        int total = count_left + count_right ;
        maxi = max(maxi , total);
        
        return 1 + max(count_left , count_right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = dfs(root);
        return maxi;
    }
};