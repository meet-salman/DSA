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
    Node *head, *tail;

    // Constructor to initialize head & tail = Null
    LinkedList() : head(nullptr), tail(nullptr) {}

    //  Element added at last
    void push_back(string val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = tail = n;
            return;
        }

        n->previous = tail;
        tail->next = n;
        tail = n;
    }

    // Element added at first
    void push_front(string val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = tail = n;
            return;
        }

        n->next = head;
        head->previous = n;
        head = n;
    }
};

int main()
{

    return 0;
}