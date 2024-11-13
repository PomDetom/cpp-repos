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
//Vector填充
    // vector<vector<int>> level;

    // void levelBuild(TreeNode* root, int height)
    // {
    //     if (root == nullptr)
    //     {
    //         return;
    //     }
    //     if (level.size() == height)
    //     {
    //         level.push_back(vector<int>());
    //     }
    //     level[height].push_back(root->val);

    //     levelBuild(root->left, height + 1);
    //     levelBuild(root->right, height + 1);

    //     return;
    // }

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // if (root == nullptr)
        // {
        //     return level;
        // }

        // levelBuild(root, 0);

        // return level;

//队列方法
        vector<vector<int>> level;

        if (root == nullptr)
        {
            return level;
        }

        vector<int> val;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            for (int n = q.size(); n--; )
            {
                TreeNode* node = q.front();
                q.pop();
                val.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            level.push_back(val);
            val.clear();
        }

        return level;
    }
};