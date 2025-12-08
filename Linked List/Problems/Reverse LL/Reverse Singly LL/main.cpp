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

    // Reverse LL
    void reverse_LL()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        stack<string> list;
        Node *current = head;
        while (current)
        {
            list.push(current->value);
            current = current->next;
        }

        current = head;
        while (current)
        {
            string val = list.top();
            list.pop();

            current->value = val;
            current = current->next;
        }
    }

    // Traverse & Display all items
    void display_list()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = head;
        while (current)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
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

    list.reverse_LL();
    list.display_list();

    return 0;
}