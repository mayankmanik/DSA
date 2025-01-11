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

int maxPathSum(Node *root, int &maxi)
{
    if (!root)
        return 0;
    int left = max(0, maxPathSum(root->left, maxi));
    int right = max(0, maxPathSum(root->right, maxi));
    maxi = max(maxi, root->data + left + right);
    return root->data + max(left, right);
}

int pathSum(Node *root)
{
    int maxi = INT_MIN;
    maxPathSum(root, maxi);
    return maxi;
}
int main()
{

    return 0;
}