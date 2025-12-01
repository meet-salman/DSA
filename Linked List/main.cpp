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
};

main()
{

    LinkedList l1;

    return 0;
}