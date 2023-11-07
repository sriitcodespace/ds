#include <iostream>
using namespace std;

#define size 100 

int stack[size];
int top = -1;

void push(int element);
void pop();
void display();
void peek();

int main() {
    int value, ch;
    
    while (1) {
        cout << "Stack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

void push(int element) {
    if (top == size - 1)
        cout << "Stack overflow\n";
    else {
        top++;
        stack[top] = element;
        cout << "inserted" << element << " onto the stack\n";
    }
}

void pop() {
    if (top == -1)
        cout << "Stack underflow\n";
    else {
        cout << "deleted " << stack[top] << " from the stack\n";
        top--;
    }
}

void display() {
    if (top == -1)
        cout << "Stack is empty\n";
    else {
        cout << "Stack elements:\n";
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Peek of stack: " << stack[top] << endl;
}

