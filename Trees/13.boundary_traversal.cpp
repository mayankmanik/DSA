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

bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}

void leftTraversal(Node *root, vector<int> &ans)
{
    Node *cur = root;
    while (!cur)
    {
        if (!isLeaf(cur))
            ans.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// to get leaf node
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    if (isLeaf(root))
        ans.push_back(root->data);
    inorder(root->right, ans);
}

// in reverse
void rightTraversal(Node *root, vector<int> &ans)
{
    Node *cur = root;
    stack<int> st;
    while (cur)
    {
        if (!isLeaf(cur))
            st.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->data);
    leftTraversal(root->left, ans);
    inorder(root, ans);
    rightTraversal(root->right, ans);
    return ans;
}
int main()
{

    return 0;
}