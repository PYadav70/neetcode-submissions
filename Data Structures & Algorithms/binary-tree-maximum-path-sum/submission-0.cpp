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
    int maxSum;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        int niche_mil_gya_answer = left + right + root->val;
        int koi_ek_achha = max(left, right) + root->val;
        int only_root_achha = root->val;

        maxSum = max({maxSum, niche_mil_gya_answer, koi_ek_achha, only_root_achha});
        return max(koi_ek_achha, only_root_achha); 
    }
    int maxPathSum(TreeNode* root) {
       maxSum = INT_MIN;
      solve(root);
      return maxSum;
    }
};
