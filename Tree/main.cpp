#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

Node *binary_tree()
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

void pre_order_traversal(Node *node)
{
    if (node == nullptr)
        return;

    // Node Left Right
    cout << node->val << " -> ";
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

void in_order_traversal(Node *node)
{
    if (node == nullptr)
        return;

    // Left Node Right
    in_order_traversal(node->left);
    cout << node->val << " -> ";
    in_order_traversal(node->right);
}

void solve()
{
    Node *root = binary_tree();
    pre_order_traversal(root);
    in_order_traversal(root);
}

int main()
{
    solve();

    return 0;
}