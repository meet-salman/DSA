#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using vec_st = vector<string>;

struct Node
{
    string value;
    Node *next;

    Node(string val) : value(val), next(nullptr) {}
};

// --- Fast I/O and helpers
static inline void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

//  Element added at last
void push_back(Node *&head, Node *&tail, string val)
{
    Node *n = new Node(val);
    if (!head)
        head = tail = n;

    else
    {
        tail->next = n;
        tail = n;
    }
}

// Construct both lists
void create_lists(Node *&head, Node *&tail)
{
    int n;
    cin >> n;

    while (n--)
    {
        string val;
        cin >> val;
        push_back(head, tail, val);
    }
}

// Arranging Node Values ODD|Even
void arrange_node_values(Node *&head)
{
    if (head->next == nullptr || head->next->next == nullptr)
        return;

    Node *current = head;
    vec_st vec;

    // Storing Odd Values
    while (current->next && current->next->next)
    {
        vec.push_back(current->value);
        current = current->next->next;
    }
    if (current)
        vec.push_back(current->value);

    current = head->next;
    // Storing Even Values
    while (current->next && current->next->next)
    {
        vec.push_back(current->value);
        current = current->next->next;
    }
    if (current)
        vec.push_back(current->value);

    // Updating Nodes values
    current = head;
    int idx = 0;
    while (current)
    {
        current->value = vec[idx++];
        current = current->next;
    }
}

// --- Solve function (logic)
void solve(Node *&head, Node *&tail)
{
    create_lists(head, tail);
    arrange_node_values(head);

    // Display updated LL
    Node *current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
}

int main()
{

    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *head = nullptr;
    Node *tail = nullptr;

    // If multiple testcases:
    // int t; cin >> t; while(t--) solve();

    solve(head, tail);

    return 0;
}