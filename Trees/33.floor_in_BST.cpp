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

int findFloor(Node *root,int key)
{
    int ans=-1;
    while (root)
    {
        if(root->data==key)
            return root->data;
        else if(root->data<key)
        {
            ans=root->data;
            root=root->right;
        }
        else
            root=root->left;
    }
    return ans;
    
}
int main()
{
    
    return 0;
}