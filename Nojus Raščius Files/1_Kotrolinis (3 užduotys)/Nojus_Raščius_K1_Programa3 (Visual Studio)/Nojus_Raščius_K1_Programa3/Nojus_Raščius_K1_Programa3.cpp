#include <iostream>
#include <assert.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void dataValidation(Node*& head, int num);
void addToList(Node*& head, int num);
void printList(Node* head);

void deleteNode(Node* head, int k_position);

int main()
{
    int num{0}, k_position=1;
    Node* head = NULL;

    dataValidation(head, num);
    addToList(head, num);
    printList(head);

    cout << "Kuri elementa norite pasalinti: ";
    cin >> k_position, cout << '\n';

    k_position = k_position - 1;

    deleteNode(head, k_position);
    
    cout << "Linked list'as po pakeitimu: \n\n";
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
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode; //jeigu listas bus tuscias tai sukuriame nauja nod'a
    }
    else {
        // jeigu netuscias tada prasibegam per lista iki galo ir pridedam i gala nauja Node'a
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printList(Node* head)
{
    int i = 0;

    Node* curr = head;

    while (curr != NULL) {
        cout << i + 1 << " Elementas = " << curr->data << "\n";
        curr = curr->next;
        i++;
    }
    cout << '\n';
}

void deleteNode(Node* head, int k_position)
{
    if (head == NULL) // jeigu tuscias
        return;

    Node* temp = head;

    if (k_position == 0) // jeigu pradzia reikia istrinti
    {
        head=temp->next; // pradzia pastumiame vienu i prieki
        free(temp); //sena pradzia panaikiname
        return;
    }

    for (int i = 0; temp != NULL && i < k_position - 1; i++) //surandu praita elemnta po kurio nori istrinti elementa
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) // jeigu pozicija yra didesne uz lista
        return;

    Node* next = temp->next->next; // issisaugau elemento pointeri po kurio bus istrintas elementas
    
    free(temp->next); //istrinu elementa
    temp->next = next; //sujungiu sarasa
}