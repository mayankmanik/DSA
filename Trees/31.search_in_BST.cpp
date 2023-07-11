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

Node *search(Node *root, int val)
{
    while (root != NULL and root->data != val)
    {
        root = val > root->data ? root->right : root->left;
    }
    return root;
}

int main()
{

    return 0;
}