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

    // Element remove from last
    void pop_back()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *toDLt = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete toDLt;
    }

    // Element remove at first
    void pop_front()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *toDlt = head;
        head = head->next;
        head->previous = nullptr;
        delete toDlt;
    }
};

int main()
{

    return 0;
}