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
    int ret;
    int longestTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return -1;
        }

        int leftLen = longestTree(root->left) + 1;
        int rightLen = longestTree(root->right) + 1;
        ret = max(leftLen + rightLen, ret);

        return max(leftLen, rightLen);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        ret = 0;
        longestTree(root);
        return ret;
    }
};