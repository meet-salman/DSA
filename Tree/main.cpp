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

    temp->left = binary_tree();
    temp->right = binary_tree();

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

void post_order_traversal(Node *node)
{
    if (node == nullptr)
        return;

    // Left Right Node
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    cout << node->val << " -> ";
}

void solve()
{
    Node *root = binary_tree();
    pre_order_traversal(root);
    in_order_traversal(root);
    post_order_traversal(root);
}

int main()
{
    solve();

    return 0;
}