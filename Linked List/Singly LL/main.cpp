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

    // Find length of LL
    int find_length()
    {
        int count = 0;
        if (!head)
            return count;
        else
        {
            Node *current = head;
            while (current)
            {
                count++;
                current = current->next;
            }
        }
        return count;
    }

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

    // Element added at position (1 - x)
    void push_at_position(int position, string val)
    {
        int len = find_length();
        if (position < 0 || position > len)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        Node *n = new Node(val);
        if (position == 0)
        {
            push_front(val);
            return;
        }
        if (position == len)
        {
            push_back(val);
            return;
        }

        Node *current = head;
        int idx = 0;
        while (current && idx < position - 1)
        {
            idx++;
            current = current->next;
        }

        n->next = current->next;
        current->next = n;
    }

    // Element remove from last
    void pop_back()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        Node *toDlt;

        while (current->next->next != nullptr)
            current = current->next;

        toDlt = current->next;
        current->next = nullptr;
        tail = current;

        delete toDlt;
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
        delete toDlt;
    }

    // Element remove at position (1 - x)
    void pop_at_position(int position)
    {
        int len = find_length();

        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (position < 0 || position >= len)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        // pop_front() if starting position
        if (position == 0)
        {
            pop_front();
            return;
        }

        // pop_back() if last position
        if (position == len - 1)
        {
            pop_back();
            return;
        }

        Node *current = head;
        Node *toDlt;
        int idx = 0;

        while (current && idx < position - 1)
        {
            idx++;
            current = current->next;
        }

        toDlt = current->next;
        current->next = toDlt->next;
        delete toDlt;
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
    list.push_back("1");
    list.push_back("2");
    list.push_back("3");
    list.push_back("4");
    list.push_back("5");
    list.push_back("6");
    list.push_back("7");
    list.push_back("8");
    list.push_back("9");
    list.push_back("10");

    list.pop_at_position(5);

    list.display_list();

    return 0;
}