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
    if (lh == -1)
        return -1;
    int rh = height(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(Node *root)
{
    return isBalanced(root) != -1;
}

int main()
{

    return 0;
}