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

Node *buildTreeHelp(vector<int> postorder, int postStart, int postEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> mp)
{
    if (postStart > postEnd or inStart > inEnd)
        return NULL;

    Node *root = new Node(postorder[postEnd]);

    int inRoot = mp[postorder[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelp(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, mp);
    root->right = buildTreeHelp(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mp);

    return root;
}
Node *buildTree(Node *root, vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    Node *root = buildTreeHelp(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}
int main()
{

    return 0;
}