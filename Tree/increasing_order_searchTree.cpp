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

TreeNode *new_node = NULL;
TreeNode *temp = NULL;

void inorder_and_store(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder_and_store(root->left);
    //& for the root of new tree, when we hit the leftmost leaf node
    if (new_node == NULL)
    {
        new_node = new TreeNode(root->val);
        temp = new_node;
    }
    else
    {
        temp->right = new TreeNode(root->val);
        temp = temp->right;
    }

    inorder_and_store(root->right);
}

//* display newly made tree
void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

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

    inorder_and_store(root);

    printTree(new_node);

    return EXIT_SUCCESS;
}