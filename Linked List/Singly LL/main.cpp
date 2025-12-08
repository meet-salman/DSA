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
            tail = nullptr;
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

    // Element remove from middle by value
    void pop_by_value(string val)
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = head;
        Node *toDlt;

        while (current->next)
        {
            // If value at head, delete & updating head
            if (current->value == val && current == head)
            {
                pop_front();
                return;
            }

            // If value at tail, delete & updating tail
            if (current->next->value == val && current->next == tail)
            {
                toDlt = current->next;
                current->next = nullptr;
                tail = current;
                delete toDlt;
                return;
            }

            // If value at somewhere btw head & tail
            if (current->next->value == val)
            {
                toDlt = current->next;
                current->next = toDlt->next;
                delete toDlt;
                return;
            }

            current = current->next;
        }

        if (current->next == nullptr)
            cout << "Value not found!" << endl;
    }

    // Update element at position (1 - x)
    void update_at_position(int position, string editedValue)
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

        Node *current = head;
        int idx = 0;
        while (current && idx < position)
        {
            idx++;
            current = current->next;
        }

        current->value = editedValue;
        return;
    }

    // Update element by value
    void update_by_value(string toEdit, string editedValue)
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = head;
        while (current && current->value != toEdit)
            current = current->next;

        if (current == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        current->value = editedValue;
    }

    // Search element at position
    void search_at_position(int position)
    {
        int length = find_length();

        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (position < 0 || position >= length)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        Node *current = head;
        int idx = 0;

        while (current && idx != position)
        {
            idx++;
            current = current->next;
        }

        cout << current->value << endl;
    }

    // Search element by value
    void search_by_value(string key)
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = head;
        int idx = 0;

        while (current && current->value != key)
        {
            idx++;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << -1 << endl;
            return;
        }

        cout << idx << endl;
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

    // Display in range (x - x)
    void display_in_range(int start, int end)
    {
        int length = find_length();

        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (start < 0)
            start = 0;
        if (end < start)
        {
            cout << "Invalid range!" << endl;
            return;
        }

        Node *current = head;
        int idx = 0;

        while (current)
        {
            if (idx >= start && idx <= end)
                cout << current->value << " ";

            idx++;
            current = current->next;
        }
    }

    // Sort list in ascending order
    void bubble_sort()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }

        else
        {
            bool isSwapped = false;
            do
            {
                isSwapped = false;
                Node *current = head;

                while (current->next)
                {
                    Node *next = current->next;

                    if (current->value > next->value)
                    {
                        swap(current->value, next->value);
                        isSwapped = true;
                    }
                    current = current->next;
                }
            } while (isSwapped);
        }
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

    list.display_list();

    return 0;
}