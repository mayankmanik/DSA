#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n)
// Space Complexity - O(1)

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

Node *flattenTree(Node *root)
{
    if (!root)
        return root;
    Node *curr = root;
    Node *prev = NULL;
    while (curr)
    {
        if (curr->left)
        {
            prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
    return root;
}

// Time Complexity - O(n)
// Space Complexity - O(n)

void helper(Node *root, Node *&prev)
{
    if (!root)
        return;
    helper(root->right, prev);
    helper(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

Node *flattenTreeRecursive(Node *root)
{
    Node *prev = NULL;
    helper(root, prev);
    return root;
}

int main()
{

    return 0;
}