#include <iostream>
using namespace std;

// Singly Linked List Node Structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to swap two nodes in a linked list
void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to partition the linked list and return the pivot node
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data < pivot) {
            i = (i == nullptr) ? low : i->next;
            swapNodes(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swapNodes(i, high);
    return i;
}

// Function to implement Quicksort for linked list
void quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pi = partition(low, high);

        quickSort(low, pi->prev);
        quickSort(pi->next, high);
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(8);
    head->next = new Node(15);
    head->next->next = new Node(4);
    // ... add other nodes

    cout << "Original list:\t";
    printList(head);

    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    quickSort(head, tail);

    cout << "Sorted list:\t";
    printList(head);

    return 0;
}
