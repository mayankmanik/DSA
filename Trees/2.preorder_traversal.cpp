#include <bits/stdc++.h>
using namespace std;

// Root Left Right

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

void preorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void preorderIterative(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        ans.push_back(node->data); 

        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
}

int main()
{

    return 0;
}