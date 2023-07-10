#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int main()
{
    Node *root=new Node(5);
    root->left=new Node(4);
    root->right=new Node(6);
    root->left->left=new Node(10);
    root->left->right=new Node(30);
    root->right->right=new Node(40);
    return 0;
}