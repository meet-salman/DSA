#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string value;
    Node *next;
    Node *previous;

    Node(string val) : value(val), next(nullptr), previous(nullptr) {}
};

struct LinkedList
{
    Node *head = nullptr,
         *tail = nullptr;

    void push_back(string val)
    {
        Node *n = new Node(val);
        if (!head)
            head = tail = n;
        else
        {
            n->previous = tail;
            tail->next = n;
            tail = n;
            // tail->next = head;   // circular
        }
    }
};

main()
{

    LinkedList l1;

    return 0;
}