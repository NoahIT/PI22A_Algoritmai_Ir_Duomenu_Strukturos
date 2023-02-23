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
int findLargest(Node* head);

void insertAfterLargest(Node* head, int& x, int largestElement);
void insertBeforeSmallest(Node* head, int& x, int smallestElement);

int main()
{
    int num{0}, x;
    Node* head = nullptr;

    dataValidation(head, num);
    addToList(head, num);
    printList(head);

    int smallestElement = findSmallest(head);
    cout << "Maziausias elementas sarase yra:   " << smallestElement << '\n';

    int largestElement = findLargest(head);
    cout << "Didziausias elementas sarase yra:  " << largestElement << '\n';
    

    cout << "\nIveskite koki skaiciu norite iterpti: ", cin >> x, cout << '\n';

    insertAfterLargest(head, x, largestElement);
    insertBeforeSmallest(head, x, smallestElement);

    cout << "List'as po pakeitimu: \n\n";
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

int findLargest(Node* head)
{
    int max = INT_MIN;

    while (head != NULL)
    {
        if (max < head->data)
            max = head->data;
        head = head->next;
    }
    return max;
}

void insertAfterLargest(Node* head, int& x, int largestElement)
{
    Node* curr = head;

    while (curr->data != largestElement)
        curr = curr->next;

    Node* new_node = new Node();
    new_node->data = x;

    new_node->next = curr->next;
    curr->next = new_node;
}

void insertBeforeSmallest(Node* head, int& x, int smallestElement)
{
    Node* curr = head;
    Node* prev_ptr = head;

    while (curr->data != smallestElement)
    {
        prev_ptr = curr;
        curr = curr->next;
    }

    Node* new_node = new Node();
    new_node->data = x;

    new_node->next = curr;
    prev_ptr->next = new_node;
}