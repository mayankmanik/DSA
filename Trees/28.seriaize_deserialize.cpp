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

string serialize(Node *root)
{
    if (!root)
        return "";

    string s = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node == NULL)
            s += "#,";
        else
            s += to_string(node->data) + ",";
        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

Node *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);   // helps to iterate over string
    string str;
    getline(s, str, ',');   // will iterate as ',' as delimeter
    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
            node->left = NULL;
        else
        {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str == "#")
            node->right = NULL;
        else
        {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{

    return 0;
}