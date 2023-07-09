#include <bits/stdc++.h>
using namespace std;

// Articulation Points of a graph are the nodes on whose removal, the graph breaks into multiple components.

int timer = 1;
void dfs(int node, int parent, vector<int> adj[], int tin[], int low[], vector<int> &vis, vector<int> &mark)
{
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, adj, tin, low, vis, mark);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] and parent != -1)
                mark[node] = 1;
            child++;
        }
        else
            low[node] = min(low[node], tin[it]);
    }
    if (child > 1 and parent == -1)
        mark[node] = 1;
}

vector<int> articulation(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, adj, tin, low, vis, mark);
        }
    }
    vector<int> articulation_point;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
            articulation_point.push_back(i);
    }
    return articulation_point;
}

int main()
{

    return 0;
}