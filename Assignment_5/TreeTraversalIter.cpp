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

void PreorderIterative(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> S;
    while (true)
    {
        while (root != NULL)
        {
            cout << root->data << " ";
            S.push(root);
            root = root->left;
        }
        if (S.empty())
        {
            return;
        }
        root = S.top();
        S.pop();
        root = root->right;
    }
}

void inorderIterative(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<TreeNode *> S;
    while (true)
    {
        while (root != NULL)
        {
            S.push(root);
            root = root->left;
        }
        if (S.empty())
        {
            return;
        }
        root = S.top();
        S.pop();
        cout << root->data << " ";
        root = root->right;
    }
}

void postorderIterative(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if (root->left)
            s1.push(root->left);

        if (root->right)
            s1.push(root->right);
    }

    while (!s2.empty())
    {
        /* code */
        int data = s2.top()->data;
        s2.pop();
        cout << data << " ";
    }
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

void levelOrderTraversalIterative(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        TreeNode *tmp = q.front();
        q.pop();
        if (tmp == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }

        cout << tmp->data << " ";
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
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
    cout << "\nPre Order Traversal : " << endl;
    PreorderIterative(root);
    cout << "\nInorder Traversal : " << endl;
    inorderIterative(root);
    cout << "\nPost Order Traversal : " << endl;
    postorderIterative(root);
    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversalIterative(root);

    return 0;
}
