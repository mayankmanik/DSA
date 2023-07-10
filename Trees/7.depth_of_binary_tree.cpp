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

int height(Node *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

int main()
{

    return 0;
}