#include <bits/stdc++.h>
using namespace std;

// here toposort works because we are relaxing edges a/c to reachability.
void topo(int i, vector<pair<int, int>> adj[], stack<int> &st, int n, vector<int> &vis)
{
    vis[i] = 1;
    for (auto &it : adj[i])
    {
        if (!vis[it.first])
        {
            topo(it.first, adj, st, n, vis);
        }
    }
    st.push(i);
    return;
}

vector<int> shotestDistance(int src, vector<pair<int, int>> adj[], int n)
{
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topo(i, adj, st, n, vis);
        }
    }
    vector<int> dis(n, 1e9);
    dis[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto &it : adj[node])
        {
            if (dis[it.first] > dis[node] + it.second)
                dis[it.first] = dis[node] + it.second;
        }
    }
    return dis;
}
int main()
{

    return 0;
}