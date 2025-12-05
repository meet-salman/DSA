#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string value;
    Node *next;

    Node(string val) : value(val), next(nullptr) {}
};

struct LinkedList
{
    Node *head, *tail;

    // Constructor to initialize head & tail = Null
    LinkedList() : head(nullptr), tail(nullptr) {}

    //  Element added at last
    void push_back(string val)
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
};

main()
{

    return 0;
}