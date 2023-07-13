#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *lca(Node *root, Node *p, Node *q)
{
    if (!root or root == p or root == q)
        return root;
    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);

    if (!left)
        return right;
    else if (!right)
        return left;
    else
        return root;
}
int main()
{

    return 0;
}