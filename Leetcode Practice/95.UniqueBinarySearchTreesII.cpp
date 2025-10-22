#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        
    }

    TreeNode* CreateNode(int n)
    {
        TreeNode* p = new TreeNode();
        if(!p) return nullptr;
        p->val = n;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

    void LNR(TreeNode* root, int n)
    {
        
    }
};