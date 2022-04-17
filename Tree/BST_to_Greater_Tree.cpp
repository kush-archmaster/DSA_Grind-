#include <bits/stdc++.h>
using namespace std;

/*
 *   Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original
 *   BST is changed to the original key plus the sum of all keys greater than the original key in BST.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int sum = 0;

TreeNode *convertBST(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    //& traverse to the rightmost leaf
    convertBST(root->right);
    sum += root->val;       //& calculating value for that node
    root->val = sum;        //& replacing the node value
    convertBST(root->left); //& now traversing in the left subtree to update the value

    return root;
}

//* display modified tree
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
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    root = convertBST(root);
    printTree(root);

    return EXIT_SUCCESS;
}