#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> adj[],int n,int startingNode,vector<int> &vis)
{
    vis[startingNode]=1;
    cout<<startingNode<<" ";
    for (auto &it : adj[startingNode])
    {
        if(!vis[it])
        {
            fun(adj,n,it,vis);
        }
    }
    
}
void dfs(vector<int> adj[],int n,int startingNode)
{
    vector<int> vis(n+1,0);
    fun(adj,n,startingNode,vis);
}

int main()
{
    
    return 0;
}