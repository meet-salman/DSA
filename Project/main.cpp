#include "template.h"

void add_link(vec_2d_pair_iint &graph)
{
    int router, next, cost;
    cin >> router >> next >> cost;

    graph[router].push_back({next, cost});
    graph[next].push_back({router, cost});
}

void add_router(vec_2d_pair_iint &graph)
{
    graph.resize(graph.size() + 1);
}

void display_network(vec_2d_pair_iint &graph)
{
    for (int i = 1; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto node : graph[i])
            cout << "{" << node.first << ", " << node.second << "} ";

        cout << endl;
    }
}

void create_network()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vec_2d_pair_iint graph((nodes + 1));

    int router, next, cost;
    int i = edges;
    while (i--)
    {
        cin >> router >> next >> cost;
        graph[router].push_back({next, cost});
        graph[next].push_back({router, cost});
    }

    add_router(graph);
    add_link(graph);
    display_network(graph);
}

int main()
{

    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
        create_network();

    // ------------
    // Sample Input
    // 5 6
    // 1 2 3
    // 1 3 5
    // 2 3 4
    // 3 4 6
    // 2 5 2
    // 4 5 1
    // 6 1 5
    // ------------

    return 0;
}