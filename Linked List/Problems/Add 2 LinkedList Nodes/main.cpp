#include <bits/stdc++.h>
using namespace std;

// --- Fast I/O and helpers
static inline void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node
{
    string value;
    Node *next;

    Node(string val) : value(val), next(nullptr) {}
};

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
void create_lists(Node *&head1, Node *&tail1, Node *&head2, Node *&tail2)
{
    int n;
    cin >> n;

    while (n--)
    {
        string val;
        cin >> val;
        push_back(head1, tail1, val);
    }

    cin >> n;
    while (n--)
    {
        string val;
        cin >> val;
        push_back(head2, tail2, val);
    }
}

// Addition of Nodes
void nodes_addition(Node *&head1, Node *&tail1, Node *&head2, Node *&tail2, Node *&head3, Node *&tail3)
{
    int carry = 0;
    Node *current1 = head1,
         *current2 = head2;
    while (current1 || current2 || carry)
    {
        int d1 = current1 ? stoi(current1->value) : 0;
        int d2 = current2 ? stoi(current2->value) : 0;
        int sum = d1 + d2 + carry;

        int dig = sum % 10;
        carry = sum / 10;
        push_back(head3, tail3, to_string(dig));
        current1 = current1 ? current1->next : nullptr;
        current2 = current2 ? current2->next : nullptr;
    }
}

// --- Solve function (main logic)
void solve(Node *&head1, Node *&tail1, Node *&head2, Node *&tail2, Node *&head3, Node *&tail3)
{
    create_lists(head1, tail1, head2, tail2);
    nodes_addition(head1, tail1, head2, tail2, head3, tail3);
}

int main()
{

    fast_io();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    Node *head3 = nullptr;
    Node *tail3 = nullptr;

    solve(head1, tail1, head2, tail2, head3, tail3);

    Node *current = head3;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }

    return 0;
}