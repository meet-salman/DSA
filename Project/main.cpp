#include "template.h"

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vec_int_2d adjList(nodes + 1);
    vec_2d_pair_iint graph((nodes + 1));

    int u, v, w;
    int i = edges;
    while (i--)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 1; i < edges; i++)
    {
        cout << i << " -> ";
        for (auto node : graph[i])
            cout << "{" << node.first << ", " << node.second << "} ";

        cout << endl;
    }
}

int main()
{

    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // ------------
    // Sample Input
    // 5 6
    // 1 2 3
    // 1 3 5
    // 2 3 4
    // 3 4 6
    // 2 5 2
    // 4 5 1
    // ------------

    return 0;
}