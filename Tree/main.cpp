#include "template.h"

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

void pre_order_traversal(Node *node)
{
    if (node == nullptr)
        return;

    // Node Left Right
    cout << node->val << " -> ";
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

void solve()
{
    Node *root = create_node();
    pre_order_traversal(root);
}

int main()
{
    solve();

    return 0;
}