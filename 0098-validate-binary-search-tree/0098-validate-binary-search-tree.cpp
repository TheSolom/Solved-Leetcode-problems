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
bool is_bst_util(TreeNode* cur, long long init_min, long long init_max) {
		if (!cur)
			return true;

		if (cur->val <= init_min || cur->val >= init_max)
			return false;

		return is_bst_util(cur->left, init_min, cur->val) && is_bst_util(cur->right, cur->val, init_max);
	}

    bool isValidBST(TreeNode* root) {
		return is_bst_util(root, LONG_LONG_MIN, LONG_LONG_MAX); 
    }
};