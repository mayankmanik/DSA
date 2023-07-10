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

void dfs(Node *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    if (!root)
        return;
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }
        if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if (it.first->right)
                st.push({it.first->right, 1});
        }
        if (it.second == 2)
        {
            postorder.push_back(it.first->data);
        }
    }
}
int main()
{

    return 0;
}