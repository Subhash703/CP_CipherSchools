#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }

    TreeNode() {
        // constructor chaining
        TreeNode(0);
    }
};

TreeNode *insert(int x, TreeNode *root){
    TreeNode *newNode = new TreeNode(x);
    if(root == NULL){
        root = newNode;
        return root;
    }
    queue<TreeNode*>Q;
    // TreeNode *curr = root;
    Q.push(root);
    while (!Q.empty())
    {
        TreeNode *tmp = Q.front();
        Q.pop();

        if (!tmp->left)
        {
            tmp->left = newNode;
            return root;
        }
        else
        {
            Q.push(tmp->left);
        }

        if (!tmp->right)
        {
            tmp->right = newNode;
            return root;
        }
        else
        {
            Q.push(tmp->right);
        }
    }
    return root;
}


void LevelOrderIterativeLineByLine(TreeNode * root) {
    if (root == NULL)
        return;
    stack<TreeNode*> s1; 
    stack<TreeNode*> s2; 
    s1.push(root); 
      
    bool flag = true; 
    while (!s1.empty()) { 
        TreeNode* temp = s1.top(); 
        s1.pop(); 
        if (temp) { 
            cout << temp->data << " "; 
            if (flag) { 
                if (temp->left) 
                    s2.push(temp->left); 
                if (temp->right) 
                    s2.push(temp->right); 
            } 
            else { 
                if (temp->right) 
                    s2.push(temp->right); 
                if (temp->left) 
                    s2.push(temp->left); 
            } 
        } 
  
        if (s1.empty()) { 
            flag = !flag; 
            swap(s1, s2); 
        } 
    } 
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    TreeNode* root = NULL;
    int n;
    cin>>n;
    while(n-->0){
        int val;
        cin>>val;
        root = insert(val, root);
    }
    LevelOrderIterativeLineByLine(root);
    return 0;
}