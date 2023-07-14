#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n)

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

Node *helper(vector<int> &pre, int &i, int bound)
{
    if (i == pre.size() or pre[i] > bound)
        return NULL;
    Node *root = new Node(pre[i++]);
    root->left = helper(pre, i, root->data);
    root->right = helper(pre, i, bound);
    return root;
}

Node *buildTree(vector<int> &pre)
{
    int i = 0;
    return helper(pre, i, INT_MAX);
}

int main()
{

    return 0;
}