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
    //递归
    // void inorder(TreeNode* root, vector<int> &res)
    // {
    //     if (root == nullptr)
    //     {
    //         return;
    //     }

    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        
        //递归
        // vector<int> res;
        // inorder(root, res);
        // return res;

        //迭代
        stack<TreeNode*> inorder;
        vector<int> res;
        
        TreeNode* cur = root;

        while (cur != nullptr || inorder.empty() != true)
        {
            if (cur != nullptr)
            {
                inorder.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = inorder.top();
                res.push_back(cur->val);
                inorder.pop();
                cur = cur->right;
            }
        }

        return res;
    }
};