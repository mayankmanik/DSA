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

vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    // node,vertical,level
    queue<pair<Node *, pair<int, int>>> q;
    // vertical,level,data
    map<int, map<int, multiset<int>>> ms;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto vertical = it.second.first;
        auto level = it.second.second;

        ms[vertical][level].insert(node->data);
        if (node->left)
            q.push({node->left, {vertical - 1, level + 1}});
        if (node->right)
            q.push({node->right, {vertical + 1, level + 1}});
    }

    for (auto it : ms)
    {
        vector<int> temp;
        for (auto jt : it.second)
        {
            temp.insert(temp.end(), jt.second.begin(), jt.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}