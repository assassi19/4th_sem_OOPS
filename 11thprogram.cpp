
#include <iostream>
// code contributed by Manoj O M

using namespace std;

#define MAX 100

class Stack
{
    int top;

public:
    int a[MAX];

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isPalindrome(int arr[], int n);
};
bool Stack::isPalindrome(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
        push(arr[i]);

    int j;
    if (n % 2)
        j = n / 2 + 1;
    else
        j = n / 2;

    while (j < n)
    {
        int top = peek();
        pop();
        if (top != arr[j])
            return false;
        j++;
    }

    return true;
}

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

int main()
{
    class Stack s;
    int choice, x;
    int arr[MAX]; // Array to check if its palindrome
    int n;

    while (true)
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if array is palindrome\n";
        cout << "4. Quit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 4)
            break;

        if (choice == 1)
        {
            cout << "Enter the element to be pushed : ";
            cin >> x;
            s.push(x);
        }
        else if (choice == 2)
        {
            x = s.pop();
            cout << "Popped element is : " << x << endl;
        }

        else if (choice == 3)
        {
            cout << "Enter the size of the array : ";
            cin >> n;
            cout << "Enter the elements of the array : ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            if (s.isPalindrome(arr, n))
                cout << "Yes it is palindrome";
            else
                cout << "No it is not palindrome";
        }
        else
        {
            cout << "Wrong choice\n";
        }

        cout << endl;
    }

    return 0;
}
