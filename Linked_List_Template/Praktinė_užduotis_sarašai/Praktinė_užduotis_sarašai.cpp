#include <iostream>

using namespace std;

//Noah's Linked list template for PI22

struct Node {
    int data;
    Node* next;
};
 
void dataValidation(Node*& head, int num);
void addToList(Node*& head, int num);
void printList(Node* head);

int main() 
{
    int num{};
    Node* head = nullptr;

    dataValidation(head, num);
    addToList(head, num);
    printList(head);

    return 0;
}

void dataValidation(Node*& head, int num)
{
    int n;

    cout << "Iveskite n kiek bus skaiciu: ";
    cin >> n, cout << '\n';
    
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " skaicius: ", cin >> num;
        addToList(head, num);
    }
    cout << '\n';
}

void addToList(Node*& head, int num)
{
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printList(Node* head)
{
    int i = 0;

    Node* curr = head;

    while (curr != nullptr) {
        cout << i + 1 << " Elementas = " << curr->data << "\n";
        curr = curr->next;
        i++;
    }
    cout << endl;
}