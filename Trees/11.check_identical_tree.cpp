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

bool isIdentical(Node *root1, Node *root2)
{
    if (!root1 or !root2)
        return root1 == root2;
    return (root1->data == root2->data and isIdentical(root1->left, root2->left) 
            and isIdentical(root1->right, root2->right));
}
int main()
{

    return 0;
}