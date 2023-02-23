#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* Next;
};

void printLL(Node* head);
void addToList(Node** head, int skaicius);
void insertInMiddle(Node* previousNode, int newData);
void insertAtBeginning(Node** headRef, int newData);

int main()
{
    int number, Size = 0, x = 99;
    Node* head = NULL;

    cout << "Iveskite LinkedLista:";
    while (cin >> number && number != 0)
    {
        addToList(&head, number);
        Size++;
    }

    printLL(head);
    Node* newList = nullptr;
    Node* current = head;

    while (current != nullptr) {
        if (current->data % 3 == 0 || current->data % 5 == 0)
        {
            Node* newNode = current;
            current->data = x;
            current->Next = newList;
            current = current->Next;
        }
        else
        {
            newList = current;
            current = current->Next;
        }
    }

    printLL(newList);
}

void printLL(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->Next;
    }
    cout << endl;
}

void addToList(Node** head, int skaicius) {
    Node* newNode = new Node;
    newNode->data = skaicius;
    newNode->Next = nullptr;
    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->Next != nullptr) {
            current = current->Next;
        }
        current->Next = newNode;
    }
}

void insertInMiddle(Node* previousNode, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->Next = previousNode->Next;
    previousNode->Next = newNode;
}

void insertAtBeginning(Node** headRef, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->Next = *headRef;
    *headRef = newNode;
}