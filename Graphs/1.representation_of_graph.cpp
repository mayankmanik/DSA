#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;    //n->no of node  m->no of edge
    cin>>n>>m;
    int adj[n+1][n+1];      // n+1 because nodes are numbered from 1 onwards
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    vector<int> arr[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    


}