#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    // Node *previous;

    Node(int val) : value(val), next(nullptr) {}
};

pair<Node *, Node *> covert_array_to_LL(vector<int> &vec)
{
    Node *head = new Node(vec[0]);
    Node *tail, *current;
    tail = current = head;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *temp = new Node(vec[i]);
        current->next = temp;
        current = tail = temp;
    }
    return make_pair(head, tail);
}

main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    pair<Node *, Node *> headTail = covert_array_to_LL(vec);
    cout << headTail.first->value << "  " << headTail.second->value;

    return 0;
}