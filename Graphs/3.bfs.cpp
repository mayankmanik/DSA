#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int n,int startingNode)
{
    vector<int> vis(n,0);
    vis[startingNode]=1;
    queue<int> q;
    q.push(startingNode);
    while (!q.empty())
    {
        auto node=q.front();
        cout<<node<<" ";
        q.pop();
        for (auto &it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
        
    }
    
}
int main()
{
    
    return 0;
}