#include "template.h"

class Network
{
private:
    string networkName;
    int noOfRouters, noOfLinks;
    vec_2d_pair_iint network;
    vec_int_2d shortestdists;
    vector<vector<vector<int>>> allPaths;

public:
    bool isNetworkUpdated;

public:
    Network(string networkName)
    {
        this->noOfRouters = 0;
        this->noOfLinks = 0;
        this->networkName = networkName;
        this->isNetworkUpdated = false;
        cout << "\n------------------------------------------\n";
        cout << "     NETWORK ESTABLISHED SUCCESSSFULLY      \n";
        cout << "------------------------------------------\n";
        display_network_details();
    }

    void display_network_details()
    {
        cout << "Network Name: " << networkName << endl
             << "Routers in Network: " << noOfRouters << " Routers" << endl
             << "Links in Network: " << noOfLinks << " Links" << endl;
    }

    void add_routers()
    {
        int routers;
        cout << "\nNo of routers to add: ";
        cin >> routers;
        noOfRouters += routers;
        network.resize(noOfRouters);

        cout << "\nNetwork expanded successfully with " << routers << " routers\n";
    }

    void add_links()
    {
        int edges;
        cout << "\nNo of links to add: ";
        cin >> edges;

        cout << endl;
        while (edges--)
        {
            int router, next, cost;
            cout << "Link router: ";
            cin >> router;
            cout << "to: ";
            cin >> next;
            cout << "with distance: ";
            cin >> cost;

            if (router >= noOfRouters || router < 0 || next >= noOfRouters || next < 0)
            {
                cout << router << "-" << next << " Out of network\n";
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

                cout << "Linking router " << router << " & " << next;
                for (int i = 0; i < 3; i++)
                {
                    cout << "." << flush;
                    this_thread::sleep_for(chrono::seconds(1));
                }

                cout << "\rRouter " << router << " & " << next << " linked successfully\n";

                noOfLinks++;
            }
        }
        cout << "\rLinking completed!\n"
             << endl;
        isNetworkUpdated = true;
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

        cout << "\n----------------------" << endl;
        cout << "  SHORTEST DISTANCES  " << endl;
        cout << "----------------------";

        for (int src = 0; src < noOfRouters; src++)
        {
            vec_bool explored(noOfRouters, false);
            vec_int dist(noOfRouters, INT_MAX);
            vec_int parent(noOfRouters, -1);

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            cout << "\nRouter " << src << " calculating its shortest distances";
            while (!pq.empty())
            {
                int currentNode = pq.top().second;
                int cost = pq.top().first;
                pq.pop();

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

            // loading...
            for (int i = 0; i < 2; i++)
            {
                cout << "." << flush;
                this_thread::sleep_for(chrono::seconds(1));
            }

            // Displaying src shortest distances
            cout << "\r" << string(80, ' ') << "\r";
            cout << "Router " << src << " -> ";
            for (auto n : dist)
            {
                if (n == INT_MAX)
                    cout << "inf ";
                else
                    cout << n << " ";
            }

            // Add shortest distances of src to all paths
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
        cout << "\n----------------------" << endl;
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

    void display_paths(int router)
    {
        cout << "\n----------------------------------------" << endl;
        cout << "   PATHS FROM ROUTER " << router << " TO ALL ROUTERS" << endl;
        cout << "------------------------------------------" << endl;

        for (int j = 0; j < allPaths[router].size(); j++)
        {
            cout << router << " -> " << j << ": { ";
            for (int k = 0; k < allPaths[router][j].size(); k++)
            {
                cout << allPaths[router][j][k] << " ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }
};

int main()
{

    // fast_io();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    Network n("CS Dept");
    n.add_routers();
    n.add_links();

    if (n.isNetworkUpdated)
        n.shortest_dists_calculation();

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