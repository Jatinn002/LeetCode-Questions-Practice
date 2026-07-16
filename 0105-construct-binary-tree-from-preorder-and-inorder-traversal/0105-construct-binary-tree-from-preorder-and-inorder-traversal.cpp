/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    int search(vector<int>& inorder, int left, int right, int value) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == value)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left,
                    int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        int idx = search(inorder, left, right, root->val);
        root->left = build(preorder, inorder, left, idx - 1);
        root->right = build(preorder, inorder, idx + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        idx = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};