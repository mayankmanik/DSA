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

int findHeightLeft(Node *root)
{
    int cnt = 0;
    while (root)
    {
        cnt++;
        root = root->left;
    }
    return cnt;
}

int findHeightRight(Node *root)
{
    int cnt = 0;
    while (root)
    {
        cnt++;
        root = root->right;
    }
    return cnt;
}

int count_nodes(Node *root)
{
    if (!root)
        return 0;

    int lh = findHeightLeft(root->left);
    int rh = findHeightRight(root->right);

    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int main()
{

    return 0;
}