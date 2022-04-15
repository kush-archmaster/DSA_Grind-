#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return NULL;

    //& if root value is smaller than low --> then we will search in the right part of the tree, ignoring the left side
    if (root->val < low)
        return trimBST(root->right, low, high);

    //& if root value is smaller than right --> then we will search in the left part of the tree, ignoring the right side
    else if (root->val > high)
        return trimBST(root->left, low, high);

    //& to traverse thru the tree
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

//& trimmed tree printing
void printTree(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root = trimBST(root, 1, 3);

    printTree(root);
    return EXIT_SUCCESS;
}