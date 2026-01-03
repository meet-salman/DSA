#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node *create_node()
{
    int val;
    cin >> val;

    Node *temp = new Node(val);

    if (val == -1)
        return nullptr;

    temp->left = create_node();
    temp->right = create_node();

    return temp;
}

void solve()
{
    Node *root = create_node();
}

int main()
{
    solve();

    return 0;
}