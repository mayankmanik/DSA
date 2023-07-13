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

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        auto node = it.first;
        auto level = it.second;
        mp[level] = node->data;

        if (node->left)
            q.push({node->left, level - 1});
        if (node->right)
            q.push({node->right, level - 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{

    return 0;
}