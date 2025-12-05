#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string value;
    Node *next;
    Node *previous;

    Node(string val) : value(val), next(nullptr), previous(nullptr) {}
};

//  Element added at last
void push_back(Node *&head, Node *&tail, string val)
{
    Node *n = new Node(val);
    if (!head)
    {

        head = tail = n;
        tail->next = head->previous = n; // circular
    }
    else
    {
        n->previous = tail;
        n->next = head;     // circular
        head->previous = n; // circular
        tail->next = n;
        tail = n;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    push_back(head, tail, "6");
    push_back(head, tail, "7");
    push_back(head, tail, "8");
    push_back(head, tail, "9");

    cout << head << " " << head->next->value << " " << head->value << endl;
    cout << tail << " " << tail->next->value << " " << tail->value << endl;

    Node *current = head;
    cout << endl;
    do
    {
        cout << current->value << " ";
        current = current->next;
    } while (current != head);

    return 0;
}