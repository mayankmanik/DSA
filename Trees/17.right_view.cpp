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

void reversePreorder(Node *root, vector<int> &ans, int level)
{
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    reversePreorder(root->right, ans, level + 1);
    reversePreorder(root->left, ans, level + 1);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    reversePreorder(root, ans, 0);
    return ans;
}

int main()
{

    return 0;
}