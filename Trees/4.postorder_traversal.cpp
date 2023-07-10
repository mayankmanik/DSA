#include <bits/stdc++.h>
using namespace std;

// Left Right Root

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

void postorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}

// Using Two Stack
void postorderIterative(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        auto node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left)
            st1.push(node->left);
        if (node->right)
            st1.push(node->right);
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
}

// Using 1 stack
void postorderIterative2(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL or !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (!temp)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
}

int main()
{

    return 0;
}