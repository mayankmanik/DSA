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

vector<vector<int>> zigzag_traversal(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();

            int idx = leftToRight ? i : size - i - 1;

            level[idx] = it->data;
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    return ans;
}

int main()
{

    return 0;
}