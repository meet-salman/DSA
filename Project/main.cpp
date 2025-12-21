#include "template.h"

void add_link(vec_2d_pair_iint &network, int &networkSize)
{
    int router, next, cost;
    cin >> router >> next >> cost;

    if (router >= networkSize || next >= networkSize)
    {
        cout << "Out of network size\n";
        return;
    }

    network[router].push_back({next, cost});
    network[next].push_back({router, cost});
}

void add_router(vec_2d_pair_iint &network, int &networkSize)
{
    network.resize(++networkSize);
}

void display_network(vec_2d_pair_iint &network, int &networkSize)
{
    for (int i = 1; i < networkSize; i++)
    {
        cout << i << " -> ";
        for (auto node : network[i])
            cout << "{" << node.first << ", " << node.second << "} ";

        cout << endl;
    }
}

void create_network()
{
    int networkSize, links;
    cin >> networkSize >> links;
    vec_2d_pair_iint network((++networkSize));

    int router, next, cost;
    int i = links;
    while (i--)
    {
        cin >> router >> next >> cost;
        network[router].push_back({next, cost});
        network[next].push_back({router, cost});
    }

    add_router(network, networkSize);
    add_link(network, networkSize);
    display_network(network, networkSize);
}

int main()
{

    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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
    // 6 2 5
    // ------------

    return 0;
}