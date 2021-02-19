#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode()
    {
        TreeNode(0);
    }
};

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int Height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    else
    {
        return 1 + max(Height(root->left), Height(root->right));
    }
}

void PrintLevel(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    //when we pass recursion to next level, we pass level-1, if we reach level == 1, we print that level
    if (level == 1)
    {
        cout << root->data << " ";
        return;
    }
    else if (level > 1)
    {
        PrintLevel(root->left, level - 1);
        PrintLevel(root->right, level - 1);
        // cout << endl;
    }
}
void levelOrderTraversal(TreeNode *root)
{
    //Find the height of the tree
    int height = Height(root);
    cout << "Height : " << height << endl;
    for (int i = 1; i <= height; i++)
    {
        PrintLevel(root, i);
    }
}

int main()
{
    /*
            10
        5       12
    7       9       9
                11
    */
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->right = new TreeNode(12);
    root->left->right = new TreeNode(9);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(11);
    cout << "\nPre Order Traversal : " << endl;
    preorder(root);
    cout << "\nInorder Traversal : " << endl;
    inorder(root);
    cout << "\nPost Order Traversal : " << endl;
    postorder(root);
    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root);

    return 0;
}
