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

bool fun(Node *node1, Node *node2)
{
    if (!node1 or !node2)
        return node1 == node2;
    return (node1->data == node2->data) and 
            (node1->left, node2->right) and
             fun(node1->right, node2->left);
}
bool isSymmetric(Node *root)
{
    if (!root)
        return true;
    return fun(root->left, root->right);
}
int main()
{

    return 0;
}