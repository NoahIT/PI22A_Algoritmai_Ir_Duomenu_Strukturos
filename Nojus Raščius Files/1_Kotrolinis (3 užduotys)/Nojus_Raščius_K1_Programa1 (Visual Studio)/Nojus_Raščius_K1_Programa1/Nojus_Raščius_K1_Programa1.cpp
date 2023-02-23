#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void dataValidation(Node*& head, int num);
void addToList(Node*& head, int num);
void printList(Node* head);

int findSmallest(Node* head);
void sumOfNodes(Node* head, int& sum, int smallestElement);

int main()
{
    int num{0}, sum=0;
    Node* head = nullptr;

    dataValidation(head, num);
    addToList(head, num);
    printList(head);

    int smallestElement = findSmallest(head);
    cout << "Maziausias elementas sarase yra:   " << smallestElement << '\n';
    
    sumOfNodes(head, sum, smallestElement);
    cout << "Kitu elementu suma yra:            " << sum << '\n';

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

int findSmallest(struct Node* head)
{
    int min = INT_MAX;

    while (head != NULL)
    {
        if (min > head->data && head->data != 0)
            min = head->data;

        head = head->next;
    }
    return min;
}

void sumOfNodes(Node* head, int& sum, int smallestElement)
{
    if (!head)
        return; // jeigu sarasas tuscias tai grazinsime NULL;

    sumOfNodes(head->next, sum, smallestElement); // rekursyviai susumuojam

    if(head->data!=smallestElement)
        sum = sum + head->data;
}