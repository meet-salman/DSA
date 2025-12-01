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

    //  Element Added at last
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

    // Element added in sorted way
    void push_sorted(string val)
    {
        Node *n = new Node(val);
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = head;
            while (current)
            {
                if (val < current->value && current->previous == nullptr)
                    push_front(val);
                else if (val > current->value && current->next == nullptr)
                    push_back(val);
                else if (val > current->value && val < current->next->value)
                {
                    n->next = current->next;
                    current->next->previous = n;
                    current->next = n;
                    n->previous = current;
                    break;
                }
                current = current->next;
            }
        }
    }
};

main()
{

    LinkedList l1;

    return 0;
}