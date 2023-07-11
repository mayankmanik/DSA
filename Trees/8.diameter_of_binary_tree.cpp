#include <bits/stdc++.h>
using namespace std;

// Time Compleity - O(N)

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

int height(Node *root, int &dia)
{
    if (!root)
        return 0;

    int lh = height(root->left, dia);
    int rh = height(root->right, dia);

    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int diameter(Node *root)
{
    int dia = 0;
    height(root, dia);
    return dia;
}

// O(N*N) soln

int findHeight(Node *root)
{
    if (!root)
        return 0;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    return 1 + max(lh, rh);
}

void diameterOfTree(Node *root, int &dia)
{
    if (!root)
        return;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    dia = max(dia, lh + rh);

    diameterOfTree(root->left, dia);
    diameterOfTree(root->right, dia);
}

int main()
{

    return 0;
}