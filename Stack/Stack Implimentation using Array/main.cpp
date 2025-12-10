#include <bits/stdc++.h>
using namespace std;

#define MAX 50
class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool is_empty()
    {
        return (top == -1);
    }

    bool is_Full()
    {
        return (top == MAX - 1);
    }

    void push(int val)
    {

        if (is_Full())
        {
            cout << "Stack Overflow!\n";
            return;
        }

        arr[++top] = val;
        cout << val << " pushed to stack\n";
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "Stack Underflow!\n";
            return;
        }

        cout << arr[top--] << " pop from stack\n";
    }

    void peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty!\n";
            cout << -1 << "\n";
        }

        cout << arr[top] << "\n";
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << "\n";
    }
};

int main()
{

    freopen("output.txt", "w", stdout);

    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();
    st.peek();
    st.pop();
    st.display();

    return 0;
}