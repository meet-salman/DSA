#include "template.h"

class Network
{
private:
    string networkName;
    int noOfRouters, noOfLinks;
    vec_2d_pair_iint network;
    vec_int_2d shortestdists;
    vector<vector<vector<int>>> allPaths;
    bool isNetworkUpdated;

public:
    Network(string networkName)
    {
        this->noOfRouters = 0;
        this->noOfLinks = 0;
        this->networkName = networkName;
        this->isNetworkUpdated = false;
        cout << "Network established successsfully\n";
        cout << "Network size: " << noOfRouters << endl;
    }

    void print_network_size()
    {
        cout << "network size: " << noOfRouters << " Routers, " << noOfLinks << " noOfLinks" << endl;
    }

    void add_routers()
    {
        int routers;
        cin >> routers;
        noOfRouters += routers;
        network.resize(noOfRouters);

        cout << "\nNetwork expanded successfully with " << routers << " routers\n";
        print_network_size();
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

            bool isAlready = false;
            for (int i = 0; i < network[router].size(); i++)
            {
                if (network[router][i].first == next)
                {
                    isAlready = true;
                    break;
                }
            }

            if (!isAlready)
            {
                network[router].push_back({next, cost});
                network[next].push_back({router, cost});

                cout << "Router " << router << " & " << next << " linked successfully\n";
                noOfLinks++;
            }
        }
        isNetworkUpdated = true;
        if (isNetworkUpdated)
            shortest_dists_calculation();
        print_network_size();
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

    void shortest_dists_calculation()
    {
        shortestdists.clear();
        allPaths.clear();

        for (int src = 0; src < noOfRouters; src++)
        {
            vec_bool explored(noOfRouters, false);
            vec_int dist(noOfRouters, INT_MAX);
            vec_int parent(noOfRouters, -1);

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty())
            {
                int currentNode = pq.top().second;
                int cost = pq.top().first;
                pq.pop();

                // cout << currentNode << " " << cost << endl;

                if (explored[currentNode])
                    continue;

                explored[currentNode] = true;

                for (auto &edge : network[currentNode])
                {
                    int neighbour = edge.first;
                    int weight = edge.second;
                    int newCost = cost + weight;

                    if (!explored[neighbour] && newCost < dist[neighbour])
                    {
                        parent[neighbour] = currentNode;
                        dist[neighbour] = newCost;
                        pq.push({newCost, neighbour});
                    }
                }
            }
            shortestdists.push_back(dist);

            // Storing all path from source
            vector<vector<int>> distsFromSrc(noOfRouters);

            for (int dest = 0; dest < noOfRouters; dest++)
            {
                if (dist[dest] == INT_MAX)
                    continue; // no path exists

                vector<int> path;
                int current = dest;

                // stop when reached at source
                while (current != -1)
                {
                    path.push_back(current);
                    current = parent[current];
                }

                reverse(all(path));
                distsFromSrc[dest] = path;
            }
            allPaths.push_back(distsFromSrc);
        }
    }

    void display_shortest_dists()
    {
        cout << "\n--------------------" << endl;
        cout << "  SHORTEST DISTANCES  " << endl;
        cout << "----------------------" << endl;
        for (int i = 0; i < shortestdists.size(); i++)
        {
            cout << "Router " << i << " -> ";
            // cout << i << " -> ";
            for (auto node : shortestdists[i])
                cout << node << " ";

            cout << endl;
        }
    }

    void display_all_paths()
    {
        cout << "\n------------------" << endl;
        cout << "      ALL PATHS     " << endl;
        cout << "--------------------" << endl;

        for (int i = 0; i < allPaths.size(); i++)
        {
            for (int j = 0; j < allPaths[i].size(); j++)
            {
                cout << i << " -> " << j << ": { ";
                for (int k = 0; k < allPaths[i][j].size(); k++)
                {
                    cout << allPaths[i][j][k] << " ";
                }
                cout << "}" << endl;
            }
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
    n.shortest_dists_calculation();
    n.display_shortest_dists();

    n.add_links();
    n.display_network();
    n.display_shortest_dists();

    n.display_all_paths();
    n.display_shortest_dists();

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
    // 4
    // 6 2 5
    // 5 4 2 -> duplicate link
    // 5 6 7
    // 1 4 1
    // ------------

    return 0;
}