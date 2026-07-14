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
    int countNode(TreeNode* root, int maxNode){
        if(root == NULL){
            return 0;
        }
        int goodNode = 0;
        if(root->val >= maxNode){
            goodNode = 1;
        }
        maxNode = max(maxNode, root->val);

        return goodNode + countNode(root->left, maxNode) + countNode(root->right, maxNode);
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return countNode(root, root->val);
    }
};
