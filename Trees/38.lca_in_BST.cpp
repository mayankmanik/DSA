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

Node *lca_of_BST(Node *root, Node *p, Node *q)
{
    if (!root)
        return root;
    while (root)
    {
        if (root->data > p->data and root->data > q->data)
            root = root->left;
        else if (root->data < p->data and root->data < q->data)
            root = root->right;
        else
            return root;
    }
    return root;
}
int main()
{

    return 0;
}