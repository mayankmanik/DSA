#include <bits/stdc++.h>
using namespace std;

// For creating a unique binary tree we require inorder and either preorder or postorder traversal
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

Node *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                      vector<int> &inorder, int inStart, int inEnd, map<int, int> mp)
{
    if (preStart > preEnd or inStart > inEnd)
        return NULL;
    Node *root = new Node(preorder[preStart]);

    int inRoot = mp[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mp);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

    return root;
}

Node *buildTree(Node *root, vector<int> inorder, vector<int> preorder)
{
    // inorder traversal contains unique element
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    Node *root = buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}
int main()
{

    return 0;
}