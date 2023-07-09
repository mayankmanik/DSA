#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int n, vector<int> adj[], int src)
{
    queue<int> q;
    q.push(src);
    vector<int> dis(n, 1e9);
    dis[src] = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (auto &i : adj[node])
        {
            if (dis[node] + 1 < dis[i])
            {
                dis[i] = 1 + dis[node];
                q.push(i);
            }
        }
    }
    for (auto &it : dis)
    {
        if (it == 1e9)
            it = -1;
    }
    return dis;
}

int main()
{

    return 0;
}