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

void inorder(Node *root, int &k, int &ans)
{
    if (!root)
        return;
    inorder(root->left, k, ans);
    k--;
    if (k == 0)
        ans = root->data;
    inorder(root->right, k, ans);
}

int kthSmallest(Node *root, int k)
{
    int ans = -1;
    inorder(root, k, ans);
    return ans;
}

int main()
{

    return 0;
}