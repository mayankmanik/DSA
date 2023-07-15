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
int findTime(unordered_map<Node *, Node *> parent, Node *target)
{
    unordered_map<Node *, bool> vis;
    queue<Node *> q;
    q.push(target);
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left and !vis[curr->left])
            {
                flag = 1;
                q.push(curr->left);
                vis[curr->left] = true;
            }
            if (curr->right and !vis[curr->right])
            {
                flag = 1;
                q.push(curr->right);
                vis[curr->right] = true;
            }
            if (parent[curr] and !vis[parent[curr]])
            {
                flag = 1;
                q.push(parent[curr]);
                vis[parent[curr]] = true;
            }
        }
        if (flag)
            time++;
    }
    return time;
}

Node *markParents(Node *root, unordered_map<Node *, Node *> &mp, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *node = q.front();
        if (node->data == start)
            res = node;
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
    return res;
}
int timeToBurn(Node *root, int start)
{
    unordered_map<Node *, Node *> parent; // node -> parent
    Node *target = markParents(root, parent, start);
    return findTime(parent, target);
}
int main()
{

    return 0;
}