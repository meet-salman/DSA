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

    // Element added at first
    void push_front(string val)
    {
        Node *n = new Node(val);
        if (!head)
            head = tail = n;
        else
        {
            n->next = head;
            head = n;
        }
    }

    // Traverse & Display all items
    void display_list()
    {
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = head;
            while (current)
            {
                cout << current->value << " ";
                current = current->next;
            }
        }
        cout << endl;
    }
};

main()
{
    LinkedList list;
    list.push_front("1");
    list.push_front("2");
    list.push_front("3");
    list.push_front("4");
    list.push_front("5");
    list.push_front("6");
    list.push_front("7");
    list.push_front("8");
    list.push_front("9");
    list.push_front("10");

    list.display_list();

    return 0;
}