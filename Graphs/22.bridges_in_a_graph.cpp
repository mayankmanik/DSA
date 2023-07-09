#include <bits/stdc++.h>
using namespace std;

// Bridges are those edges in a graph whose removal will divide graph in two or more parts.
int timer=1;
void dfs(int node, int parent, vector<int> adj[], int n, vector<int> &vis, vector<vector<int>> &bridges,
         int time[], int lowestTime[])
{
    vis[node] = 1;
    time[node] = timer;
    lowestTime[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, adj, n, vis, bridges, time, lowestTime);
            lowestTime[node] = min(lowestTime[node], lowestTime[it]);

            if (lowestTime[it] > time[node])
                bridges.push_back({node, it});
        }
        else
        {
            lowestTime[node] = min(lowestTime[node], lowestTime[it]);
        }
    }
}
vector<vector<int>> find_bridges(vector<int> adj[], int n)
{
    vector<vector<int>> bridges;
    vector<int> vis(n, 0);
    int time[n];
    int lowestTime[n];
    dfs(0, -1, adj, n, vis, bridges, time, lowestTime);
    return bridges;
}

int main()
{

    return 0;
}