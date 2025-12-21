#include "template.h"

class Network
{
private:
    string networkName;
    int noOfRouters, links;
    vec_2d_pair_iint network;

public:
    Network(string networkName)
    {
        this->noOfRouters = 0;
        this->links = 0;
        this->networkName = networkName;
        cout << "Network established successsfully\n";
        cout << "Network size: " << noOfRouters << endl;
    }

    void network_size()
    {
        cout << "network size: " << noOfRouters << " Routers, " << links << " Links" << endl;
    }

    void add_routers()
    {
        int routers;
        cin >> routers;
        noOfRouters += routers;
        network.resize(noOfRouters);

        cout << "\nNetwork expanded successfully with " << routers << " routers\n";
        network_size();
    }

    void add_links()
    {
        int edges;
        cin >> edges;

        cout << endl;
        while (edges--)
        {
            int router, next, cost;
            cin >> router >> next >> cost;

            if (router >= noOfRouters || router < 0 || next >= noOfRouters || next < 0)
            {
                cout << router << "—" << next << " Out of network\n";
                continue;
            }

            if (cost < 0)
            {
                cout << "Invalid cost at: " << router << "—" << next << endl;
                continue;
            }

            network[router].push_back({next, cost});
            network[next].push_back({router, cost});

            cout << "Router " << router << " & " << next << " linked successfully\n";
            links++;
        }
        network_size();
    }

    void display_network()
    {
        cout << endl;
        for (int i = 0; i < noOfRouters; i++)
        {
            // cout <<"Router " <<i << " -> ";
            cout << i << " -> ";
            for (auto node : network[i])
                cout << "{" << node.first << ", " << node.second << "} ";

            cout << endl;
        }
    }
};

int main()
{

    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Network n("CS Dept");
    n.add_routers();
    n.add_links();
    n.display_network();
    n.add_routers();
    n.add_links();
    n.display_network();

    // ------------
    // Sample Input
    // 6
    // 7
    // 0 2 5
    // 0 1 3
    // 1 3 7
    // 2 3 6
    // 2 4 1
    // 3 5 8
    // 4 5 2
    // 1
    // 3
    // 6 2 5
    // 5 6 7
    // 1 4 1
    // ------------

    return 0;
}