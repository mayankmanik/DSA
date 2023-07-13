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

bool helper(Node *root, long long mini, long long maxi)
{
    if (!root)
        return true;
    if (root->data >= maxi or root->data <= mini)
        return false;
    return helper(root->left, mini, root->data) and helper(root->right, root->data, maxi);
}

bool isBST(Node *root)
{
    return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
}
int main()
{

    return 0;
}