#include "template.h"

// loading...
void loading()
{
    for (int i = 0; i < 2; i++)
    {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void clear_line()
{
    // Clear current line
    cout << "\033[2K\r";
}

void clear_prev_line()
{
    // Move cursor up one line and clear it
    cout << "\033[A\033[2K\r";
}

class PC
{
public:
    int pcId;
    int routerConnected;

public:
    PC(int id, int router) : pcId(id), routerConnected(router)
    {
        cout << BLUE << "PC " << id << " connected with router " << routerConnected << RESET << "\n";
    }
};

class Network
{
private:
    string networkName;
    int noOfRouters, noOfLinks;
    vec_2d_pair_iint network;
    vec_int_2d shortestdists;
    vector<vector<vector<int>>> allPaths;
    vector<PC> pcs;

public:
    bool isNetworkUpdated;

public:
    Network(string networkName)
    {
        this->noOfRouters = 0;
        this->noOfLinks = 0;
        this->networkName = networkName;
        this->isNetworkUpdated = false;
        cout << BG_BLUE << WHITE << BOLD
             << "------------------------------------------" << RESET << "\n";
        cout << BG_BLUE << WHITE << BOLD
             << "     NETWORK ESTABLISHED SUCCESSFULLY     " << RESET << "\n";
        cout << BG_BLUE << WHITE << BOLD
             << "------------------------------------------" << RESET << "\n";

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
        cout << "No of routers to add: ";
        cin >> routers;
        noOfRouters += routers;
        network.resize(noOfRouters);

        cout << BLUE
             << "Network expanded successfully with "
             << routers << " routers\n"
             << RESET;
    }

    void add_links()
    {
        int edges;
        cout << "No of links to add: ";
        cin >> edges;

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
                cout << RED << router << "-" << next
                     << " Out of network" << RESET << endl;
                continue;
            }

            if (cost < 0)
            {
                cout << RED << "Invalid cost at: "
                     << router << "—" << next << RESET << endl;
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

                // Showing progress
                cout << YELLOW << "Linking router "
                     << router << " & " << next << RESET;
                loading();
                clear_line();
                cout << GREEN
                     << "Router " << router << " & " << next
                     << " linked successfully" << RESET << endl;
                noOfLinks++;
            }
        }
        cout << BLUE << "\rLinking completed!" << RESET << "\n\n";
        isNetworkUpdated = true;
    }

    void add_pc(int id, int router)
    {
        cout << YELLOW << "Connecting PC " << id << " with router " << router << "...\n"
             << RESET;
        loading();
        clear_prev_line();
        pcs.push_back(PC(id, router));
    }

    void display_network_table()
    {
        cout << BG_WHITE << BLUE << BOLD
             << "             NETWORK TOPOLOGY             "
             << RESET << "\n\n";

        cout << BOLD
             << BLUE << left << setw(10) << "Router"
             << GREEN << setw(20) << "Connected Router"
             << RED << setw(10) << "Cost"
             << RESET << "\n";

        cout << BOLD << CYAN
             << "------------------------------------------"
             << RESET << "\n";

        for (int i = 0; i < noOfRouters; i++)
        {
            for (auto link : network[i])
            {
                cout << BLUE << left << setw(10) << i
                     << GREEN << setw(20) << link.first
                     << RED << setw(10) << link.second
                     << RESET << "\n";
            }
        }

        cout << BOLD << CYAN
             << "------------------------------------------"
             << RESET << "\n";
    }

    void display_network_adj_list()
    {
        cout << BG_WHITE << BLUE << BOLD
             << "             NETWORK TOPOLOGY             "
             << RESET << "\n";

        cout << BOLD << CYAN
             << "------------------------------------------"
             << RESET << "\n";

        for (int i = 0; i < noOfRouters; i++)
        {
            cout << BOLD << BLUE
                 << "Router " << i << ":"
                 << RESET << "\n";

            for (auto link : network[i])
            {
                cout << GREEN << "  -> Router " << link.first
                     << RED << " (Cost: " << link.second << ")"
                     << RESET << "\n";
            }

            cout << "\n";
        }

        cout << BOLD << CYAN
             << "------------------------------------------"
             << RESET << "\n";
    }

    void display_network_topology()
    {
        cout << BG_WHITE << BLUE << BOLD
             << "             NETWORK TOPOLOGY             " << RESET << "\n";

        for (int i = 0; i < noOfRouters; i++)
        {
            cout << CYAN << "Router " << i << RESET << " -> ";

            for (auto link : network[i])
                cout << GREEN << "{" << link.first << ", " << link.second << "} " << RESET;

            cout << endl;
        }
    }

    void shortest_distance_calculation()
    {
        shortestdists.clear();
        allPaths.clear();

        cout << YELLOW << "Calculating shortest distances..." << RESET << "\n";
        // cout << BG_WHITE << BLUE << BOLD
        //      << "------------------------------------------" << RESET << "\n";
        // cout << BG_WHITE << BLUE << BOLD
        //      << "            SHORTEST DISTANCES            " << RESET << "\n";
        // cout << BG_WHITE << BLUE << BOLD
        //      << "------------------------------------------" << RESET;

        for (int src = 0; src < noOfRouters; src++)
        {
            vec_bool explored(noOfRouters, false);
            vec_int dist(noOfRouters, INT_MAX);
            vec_int parent(noOfRouters, -1);

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            cout << YELLOW
                 << "Router " << src << " calculating its shortest distances"
                 << RESET;
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

            loading();

            // Add shortest distances of src to all paths
            shortestdists.push_back(dist);

            // Displaying src shortest distances
            cout << YELLOW
                 << "\nRouter " << src << " constructing its shortest paths"
                 << RESET;
            // display_node_shortest_distance(src);

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

            loading();
            clear_line();
            clear_prev_line();
        }
        clear_prev_line();
        cout << BLUE << "Shortest distances calculated!" << RESET << "\n";
        isNetworkUpdated = false;
    }

    void display_node_shortest_distance(int src)
    {
        cout << CYAN << "Router " << src << RESET << " -> ";
        for (auto node : shortestdists[src])
        {
            if (node == INT_MAX)
                cout << RED << "inf " << RESET;
            else
                cout << node << " ";
        }
    }

    void display_all_nodes_shortest_distances()
    {
        cout << BG_WHITE << BLUE << BOLD
             << "------------------------------------------" << RESET << "\n";
        cout << BG_WHITE << BLUE << BOLD
             << "            SHORTEST DISTANCES            " << RESET << "\n";
        cout << BG_WHITE << BLUE << BOLD
             << "------------------------------------------" << RESET << "\n";

        for (int i = 0; i < shortestdists.size(); i++)
        {
            cout << CYAN << "Router " << i << RESET << " -> ";
            for (auto node : shortestdists[i])
            {
                if (node == INT_MAX)
                    cout << RED << "inf " << RESET;
                else
                    cout << node << " ";
            }
            cout << endl;
        }
    }

    void display_shortest_paths(int router)
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

    void send_packet(int srcPc, int destPc)
    {
        cout << YELLOW << "\nPacket sending from PC " << srcPc << " to PC " << destPc << "..." << RESET << "\n";
        loading();
        clear_line();

        int srcRouter = -1, destRouter = -1;
        for (auto &pc : pcs)
        {
            if (pc.pcId == srcPc)
                srcRouter = pc.routerConnected;
            if (pc.pcId == destPc)
                destRouter = pc.routerConnected;
        }

        if (srcRouter == -1 || destRouter == -1)
        {
            cout << RED << "Invalid PC ID(s)" << RESET << "\n";
            return;
        }

        cout << GREEN << "Packet sending started" << RESET << "\n";
        loading();
        clear_line();
        cout << "PC " << srcPc << " -> Router " << srcRouter << endl;

        vector<int> &path = allPaths[srcRouter][destRouter];
        // Check if no route available
        if (path.empty())
        {
            cout << RED << "No route available" << RESET << "\n";
            return;
        }

        // sending on routers
        int next = srcRouter;
        for (auto &node : path)
        {
            cout << "Packet at router " << node << endl;
            loading();
            clear_line();
        }

        cout << "Router " << destRouter << " -> PC " << destPc << endl;
        cout << BLUE << "Packet delivered successfully!" << RESET << "\n";
    }
};

int main()
{
    Network n("CS Dept");

    int choice;
    do
    {
        cout << "\n=========== NETWORK MENU ===========\n";
        cout << "1. Add Routers\n";
        cout << "2. Add Links\n";
        cout << "3. Display Network Topology\n";
        cout << "4. Calculate Shortest Distances\n";
        cout << "5. Add PC\n";
        cout << "6. Send Packet\n";
        cout << "7. Display All Nodes Shortest Distances\n";
        cout << "8. Display Shortest Paths from a Router\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            n.add_routers();
            break;
        case 2:
            n.add_links();
            break;
        case 3:
            n.display_network_topology();
            break;
        case 4:
            if (n.isNetworkUpdated)
                n.shortest_distance_calculation();
            else
                cout << "network is not updated!\n";
            break;
        case 5:
        {
            int pcId, router;
            cout << "Enter PC ID: ";
            cin >> pcId;
            cout << "Enter Router to connect: ";
            cin >> router;
            n.add_pc(pcId, router);
            break;
        }
        case 6:
        {
            int srcPc, destPc;
            cout << "Enter Source PC ID: ";
            cin >> srcPc;
            cout << "Enter Destination PC ID: ";
            cin >> destPc;
            n.send_packet(srcPc, destPc);
            break;
        }
        case 7:
            n.display_all_nodes_shortest_distances();
            break;
        case 8:
        {
            int router;
            cout << "Enter Router ID: ";
            cin >> router;
            n.display_shortest_paths(router);
            break;
        }
        case 9:
        {
            n.display_network_table();
            break;
        }
        case 10:
        {
            n.display_network_adj_list();
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

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