#include <iostream>

//Noah's Double Linked List Template for PI22

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayList() {
        Node* current = head;

        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Nodes of doubly linked list: " << endl;

        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void dataValidation() {
        int n, num;

        cout << "Iveskite n kiek bus skaiciu: ";
        cin >> n, cout << '\n';

        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " skaicius: ", cin >> num;
            addNode(num);
        }
        cout << '\n';
    }
};

int main() {
    DoublyLinkedList dll;

    dll.dataValidation();
    dll.displayList();

    return 0;
}
