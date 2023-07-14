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

Node *inorderSuccessor(Node *root, Node *p)
{
    Node *ans = NULL;
    while (root != NULL)
    {
        if (root->data > p->data)
        {
            ans = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ans;
}
int main()
{

    return 0;
}