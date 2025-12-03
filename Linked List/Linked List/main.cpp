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
    LinkedList()
    {
        head = tail = nullptr;
    }

    // Find length of LL
    int find_length()
    {
        int count = 0;
        if (!head)
            return count;
        else
        {
            Node *current = head;
            do
            {
                count++;
                current = current->next;
            } while (current != head);
            // cout << "Length: " << count << endl;
        }
        return count;
    }

    //  Element added at last
    void push_back(string val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = tail = n;
            head->previous = tail;
            tail->next = head; // circular
        }
        else
        {
            n->previous = tail;
            n->next = head; // circular
            tail->next = n;
            tail = n;
            head->previous = tail; // circular
        }
    }

    // Element added in sorted way
    void push_sorted(string val)
    {
        Node *n = new Node(val);
        if (!head)
            push_back(val);
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

    // Element added at position (1 - x)
    void push_at_position(int position, string val)
    {
        Node *n = new Node(val);
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = head;
            int idx = 1;
            while (current)
            {
                if (position == idx && current->previous == nullptr)
                {
                    push_front(val);
                    break;
                }
                else if (position == idx && current->next == nullptr)
                {
                    push_back(val);
                    break;
                }
                else if (position == idx)
                {
                    n->next = current->next;
                    current->next->previous = n;
                    current->next = n;
                    n->previous = current;
                    break;
                }
                else
                {
                    idx++;
                    current = current->next;
                }
            }
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
            n->previous = tail; // circular
            n->next = head;
            head->previous = n;
            head = n;
            tail->next = head; // circular
        }
    }

    // Element remove from last
    void pop_back()
    {
        if (!head)
            cout << "List is empty!" << endl;
        else if (head == tail)
        {
            Node *toDlt = head;
            head = tail = nullptr;
            delete toDlt;
        }
        else
        {
            Node *temp = tail;
            tail = tail->previous;
            tail->next = head;     // circular
            head->previous = tail; // circular
            delete temp;
        }
    }

    // Element remove from middle by value
    void pop_by_value(string val)
    {
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = head;
            while (current)
            {
                if (current->value == val && current->previous == nullptr)
                    pop_front();
                else if (current->value == val && current->next == nullptr)
                    pop_back();
                else if (current->value == val)
                {
                    current->previous->next = current->next;
                    break;
                }
                current = current->next;
            }
        }
    }

    // Element remove at position (1 - x)
    void pop_at_position(int position)
    {
        int length = find_length();

        if (!head)
            cout << "List is empty!" << endl;
        else if (position < 1 || position >= length)
            cout << "Invalid Position!" << endl;
        else
        {
            Node *current = head;
            int idx = 0;
            do
            {
                if (idx == position && current->previous == nullptr)
                {
                    pop_front();
                    return;
                }
                else if (idx == position && current->next == nullptr)
                {
                    pop_back();
                    return;
                }
                if (idx == position)
                {
                    current->next->previous = current->previous;
                    current->previous->next = current->next;
                    return;
                }
                else
                {
                    idx++;
                    current = current->next;
                }
            } while (current != head);
        }
    }

    // Element remove at first
    void pop_front()
    {
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *temp = head;
            head = head->next;
            head->previous = tail; // circular
            tail->next = head;     // circular
            delete temp;
        }
    }

    // Update element by value
    void update_by_value(string toEdit, string editedValue)
    {
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = head;
            while (current)
            {
                if (current->value == toEdit)
                {
                    current->value = editedValue;
                    break;
                }
                current = current->next;
            }
        }
    }

    // Update element at position (1 - x)
    void update_at_position(int position, string editedValue)
    {
        int length = find_length();

        if (!head)
            cout << "List is empty!" << endl;
        else if (position < 1 || position >= length)
            cout << "Invalid Position!" << endl;
        else
        {
            Node *current = head;
            int idx = 0;
            do
            {
                if (idx == position)
                {
                    current->value = editedValue;
                    return;
                }
                idx++;
                current = current->next;
            } while (current != head);
        }
    }

    // Search element by value
    void search_by_value(string key)
    {
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = head;
            int idx = 0;
            do
            {
                if (current->value == key)
                {
                    cout << idx << endl;
                    return;
                }
                else
                {
                    idx++;
                    current = current->next;
                }
            } while (current != head);
            cout << -1 << endl;
        }
    }

    // Search element at position
    void search_at_position(int position)
    {
        int length = find_length();

        if (!head)
            cout
                << "List is empty!" << endl;
        else if (position < 1 || position >= length)
            cout
                << "Invalid Position!" << endl;
        else
        {
            Node *current = head;
            int idx = 0;
            do
            {
                if (idx == position)
                {
                    cout << current->value << endl;
                    return;
                }
                else
                {
                    idx++;
                    current = current->next;
                }
            } while (current != head);
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
            do
            {
                cout << current->value << " ";
                current = current->next;
            } while (current != head);
        }
        cout << endl;
    }

    // Traverse in reverse & Display all items
    void display_list_reverse()
    {
        if (!head)
            cout << "List is empty!" << endl;
        else
        {
            Node *current = tail;
            do
            {
                cout << current->value << " ";
                current = current->previous;
            } while (current != tail);
        }
        cout << endl;
    }

    // Display in range (x - x)
    void display_in_range(int start, int end)
    {
        int length = find_length();

        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (start < 1)
            start = 1;
        if (end >= length)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        Node *current = head;
        int idx = 0;
        do
        {
            if (idx >= start && idx <= end)
                cout << current->value << " ";

            idx++;
            current = current->next;
        } while (current != head);
    }
};

main()
{

    LinkedList l1;
    l1.push_back("1");
    // l1.push_back("2");
    // l1.push_back("3");
    // l1.push_back("4");
    // l1.push_back("5");
    // l1.push_back("6");
    // l1.push_back("7");
    // l1.push_back("8");
    // l1.push_back("9");
    // l1.push_back("10");

    // l1.update_at_position(5, "s");
    // l1.pop_at_position(5);
    l1.pop_back();
    l1.display_list();

    cout << endl;

    // l1.find_length();
    // l1.display_list();
    cout << endl;

    return 0;
}