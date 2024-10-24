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
    void findCanonicalForm(TreeNode* root) {
        if (!root) return;

        // Post-order traversal: first bring subtrees in their canonical form
        findCanonicalForm(root->left);
        findCanonicalForm(root->right);

        if (!root->right) return;
        // Swap subtrees, so that left is non-empty
        if (!root->left) {
            root->left = root->right;
            root->right = NULL;
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // Swap subtrees
        if (left->val > right->val) {
            root->left = right;
            root->right = left;
        }
    }

    bool areEquivalent(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return areEquivalent(root1->left, root2->left) &&
               areEquivalent(root1->right, root2->right);
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);
        return areEquivalent(root1, root2);
    }
};