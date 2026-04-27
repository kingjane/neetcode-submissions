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
    bool dfs (TreeNode* curr, long l, long r) {
        if (curr && (l > curr->val || curr->val > r))
            return false;
        if (!curr) return true;
        return dfs(curr->left, l, (long)curr->val - 1) && dfs(curr->right, (long)curr->val + 1, r);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};