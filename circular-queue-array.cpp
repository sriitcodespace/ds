#include <iostream>
using namespace std;

#define size 100

int queue[size];
int front = -1, rear = -1;

void enqueue(int element);
void dequeue();
void display();

int main() {
    int value, ch;

    while (1) {
        cout << "Circular Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

void enqueue(int element) {
    if ((rear + 1) % size == front)
        cout << "Queue overflow\n";
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = element;
    } else {
        rear = (rear + 1) % size;
        queue[rear] = element;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Queue underflow\n";
    } else if (front == rear) {
        cout << "Element deleted: " << queue[front] << endl;
        front = rear = -1;
    } else {
        cout << "Element deleted: " << queue[front] << endl;
        front = (front + 1) % size;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        cout << "Queue is empty\n";
    } else {
        cout << "Elements present in the queue:";
        for (i = front; i != rear; i = (i + 1) % size) {
            cout << "\n" << queue[i];
        }
        cout << "\n" << queue[i]; // Display the last element
    }
}

