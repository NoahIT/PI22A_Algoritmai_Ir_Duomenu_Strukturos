#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* Next;
};

void printLL(Node* head);
void addToList(Node** head, int skaicius);

/// ////

int main()
{
    int number, counter = 0;
    Node* head = nullptr;

    cout << "Iveskite LinkedList:"; 
    while (cin >> number && number != 0)
    {
        addToList(&head, number);
    }

    printLL(head);

    Node* current = head;

    while (current != nullptr)
    {
        if (counter == 1)
        {
            if (current->Next == nullptr)
            {
                current->Next = nullptr;
            }
            else
            {
                Node* temp = current->Next;
                current->Next = current->Next->Next;
                free(temp);
            }
        }
        counter++;
        current = current->Next;
    }

    printLL(head);
}

////////

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