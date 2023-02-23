#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = NULL;
    }

    bool isEmpty() {
        return (tail == NULL);
    }

    void addNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (isEmpty()) {
            newNode->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        if (isEmpty()) {
            cout << "Error: List is empty" << endl;
            return;
        }

        Node* current = tail->next;
        Node* prev = tail;

        do {
            if (current->data == value) {
                if (current == tail) {
                    tail = prev;
                }

                prev->next = current->next;
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != tail->next);

        cout << "Error: Node not found in list" << endl;
    }

    void displayList() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Nodes of circular linked list: " << endl;

        Node* current = tail->next;

        do {
            cout << current->data << endl;
            current = current->next;
        } while (current != tail->next);
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
    CircularLinkedList cll;

    cll.dataValidation();
    cll.displayList();

    //Delete:
    //cll.deleteNode(3);
    //cll.displayList();

    return 0;
}
