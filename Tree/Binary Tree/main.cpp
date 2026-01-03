#include "template.h"

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

struct Tree
{
    Node *root;
    Tree() : root(nullptr) {}

    void add_root(int val)
    {
        if (!root)
        {
            Node *n = new Node(val);
            root = n;

            cout << (n->left ? to_string(n->left->val) : "null") << " "
                 << n->val << " "
                 << (n->right ? to_string(n->right->val) : "null") << "\nroot added\n\n";
        }
        else
        {
            cout << "Root already defined!\n";
            return;
        }
    }

    void add_node(Node *parent)
    {
        int left, right;
        cin >> left >> right;

        if (left != -1)
            parent->left = new Node(left);

        if (right != -1)
            parent->right = new Node(right);
    }
};

void solve()
{
    Tree t;

    queue<Node *> q;
    int rootVal;
    cin >> rootVal;

    t.add_root(rootVal);
    q.push(t.root);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        t.add_node(parent);
        if (parent->left != nullptr)
            q.push(parent->left);
        if (parent->right != nullptr)
            q.push(parent->right);

        cout << (parent->left ? to_string(parent->left->val) : "null") << " "
             << parent->val << " "
             << (parent->right ? to_string(parent->right->val) : "null") << "\n";
    }
}

int main()
{
    file_io();
    solve();

    return 0;
}