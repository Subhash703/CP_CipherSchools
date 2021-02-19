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

int Height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    else
    {
        return 1 + max(Height(root->left), Height(root->right));
    }
}

void leftView(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            if (i == 0)
            {
                cout << root->data << " ";
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
}
void rightView(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            if (i == size - 1)
            {
                cout << root->data << " ";
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
}

void topView(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
}
void bottomView(TreeNode *root)
{
    if (root == NULL)
        return;
}

int main()
{
    /*
            10
          /    \
        5       12
      /   \       \
    7       9       9
                  /
                11
    */
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->right = new TreeNode(12);
    root->left->right = new TreeNode(9);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(11);
    cout << "Left View : " << endl;
    leftView(root);

    cout << "\nRight View : " << endl;
    rightView(root);

    cout << "\nTop View : " << endl;
    topView(root);
    return 0;
}
