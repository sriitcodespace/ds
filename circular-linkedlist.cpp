#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

// Insert a new node at the end of the list
void insertNode(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = head;
    }
}

// Delete the first occurrence of the given value in the list
void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        return;
    }
    Node* cur = head;
    if (cur->data == value) {
        while (cur->next != head) {
            cur = cur->next;
        }
        head = head->next;
        delete cur;
    } else {
        while (cur->next != head && cur->next->data != value) {
            cur = cur->next;
        }
        if (cur->next->data == value) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }
}

// Display the list by printing each node's data
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
}
