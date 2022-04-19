#include <bits/stdc++.h>
using namespace std;

//* simplest solution is to find inorder traversal and then print the Kth largest/smallest element

//* Method 2
//* maintain a counter while doing inorder traversal and instead of storing the nodes, just increment the count

/*
*Types of Traversals

*1) Recursive, Stack =>  TC : O(N)
*                        SC : O(N)

*2) Morris Traversal =>  TC : O(N)
*                        SC : O(1)

*/
int counter = 0; //& maintaining a counter to determine the answer
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder_Traversal(TreeNode *root, int k, int &answer)
{
    if (root == NULL)
        return;

    inorder_Traversal(root->left, k, answer);
    counter++;
    if (counter == k) //& if count becomes equal to k
    {
        answer = root->val;
        return;
    }
    inorder_Traversal(root->right, k, answer);
}

//* Method 1
//& maintain a counter while doing inorder traversal and instead of storing the nodes, just increment the count
/*
* Types of Traversals

*1) Recursive, Stack =>  TC : O(N)
*                        SC : O(N)

*2) Morris Traversal =>  TC : O(N)
*                        SC : O(1)

*/

int kthSmallest_recursive(TreeNode *root, int k)
{
    // simplest solution is to find inorder traversal and then print the Kth largest/smallest element

    //* Recursive
    int ans = -1; //& initialising ans
    inorder_Traversal(root, k, ans);

    //* Morris Traversal

    return ans;
}

int kthSmallest_morris(TreeNode *root, int k)
{
    int ku;
    return ku;
}

/*
1) For kth largest , do a single traversal and find the num of nodes in tree, then find the (n-k)th smallest node with this logic only
2) other way can be reverse inorder traversal, (right root left), in that case we will be traversing in decreasing order
*/

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);

    cout << "Recursive Inorder Traversal : " << kthSmallest_recursive(root, 3) << endl
         << "Morris Inorder Traversal : " << kthSmallest_morris(root, 2) << endl;
    return EXIT_SUCCESS;
}