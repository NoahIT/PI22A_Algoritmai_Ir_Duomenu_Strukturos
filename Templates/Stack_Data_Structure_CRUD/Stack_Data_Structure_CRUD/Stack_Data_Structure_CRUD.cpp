#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Stack {
private:
    int top;           // Index'as virsutinio elemento
    int arr[MAX_SIZE]; // Masyvas elementams talpinti

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Error: Stack is full" << endl;
            return;
        }

        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Contents of stack: ";

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    void dataValidation() {
        int n, num;

        cout << "Iveskite n kiek bus skaiciu: ";
        cin >> n, cout << '\n';

        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " skaicius: ", cin >> num;
            push(num);
        }
        cout << '\n';
    }
};

int main() {
    Stack s;

    s.dataValidation();
    s.display();

    return 0;
}
