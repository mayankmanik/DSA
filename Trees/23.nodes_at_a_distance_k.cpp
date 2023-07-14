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

void markParents(Node *root, unordered_map<Node *, Node *> &mp)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node->left)
        {
            mp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
}
vector<int> distanceK(Node *root, int k, Node *target)
{
    vector<int> ans;
    unordered_map<Node *, Node *> parent;   // node -> parent
    markParents(root, parent);

    unordered_map<Node *, bool> vis;
    queue<Node *> q;
    q.push(target);
    vis[target] = true;

    int curr_level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (curr_level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left and !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left] = true;
            }
            if (curr->right and !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right] = true;
            }
            if (parent[curr] and !vis[parent[curr]])
            {
                q.push(parent[curr]);
                vis[parent[curr]] = true;
            }
        }
    }
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}
int main()
{

    return 0;
}