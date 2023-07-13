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

int findCeil(Node *root,int key)
{
    int ans=-1;
    while (root)
    {
        if(root->data==key)
            return key;
        else if(root->data>key)
        {
            ans=root->data;
            root=root->left;
        }
        else
            root=root->right;
    }
    return ans;
    
}
int main()
{
    
    return 0;
}