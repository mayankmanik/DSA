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

Node *findLastRight(Node *root)
{
    if (root->right == NULL)
        return root;
    return findLastRight(root->right);
}

Node *helper(Node *root)
{
    if (!root->left)
        return root->right;
    else if (!root->right)
        return root->left;
    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node *deleteInBST(Node *root, int key)
{
    if (!root)
        return root;
    if (root->data == key)
        return helper(root);
    Node *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left and root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right and root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}
int main()
{

    return 0;
}