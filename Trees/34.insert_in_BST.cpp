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

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    Node *temp = root;
    while (true)
    {
        if (temp->data <= val)
        {
            if (temp->right)
                temp = temp->right;
            else
            {
                temp->right = new Node(val);
                break;
            }
        }
        else
        {
            if (temp->left)
                temp = temp->left;
            else
            {
                temp->left = new Node(val);
                break;
            }
        }
    }
    return root;
}
int main()
{

    return 0;
}