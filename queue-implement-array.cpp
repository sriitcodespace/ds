#include <iostream>
using namespace std;

#define size 100

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int element);
void dequeue();
void display();

int main() {
    int value, ch;

    while (1) {
        cout << "Queue Operations:\n";
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
    if (rear == size - 1)
        cout << "Queue overflow\n";
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
        cout << "Enqueued " << element << " into the queue\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue underflow\n";
        front = rear = -1;
    } else {
        cout << "Dequeued " << queue[front] << " from the queue\n";
        front++;
    }
}

void display() {
    if (front == -1)
        cout << "Queue is empty\n";
    else {
        cout << "Queue elements:\n";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

