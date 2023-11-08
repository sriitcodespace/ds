#include <iostream>
using namespace std;

// Struct for defining the nodes in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Global variables for root, new_node, temp, cur, parent, is, and sp
struct node *root = NULL, *new_node, *New, *cur, *parent, *is, *sp;

// Function to create a new node
void create() {
    New = new node();
    cout << "Enter element: ";
    cin >> New->data;
    New->left = NULL;
    New->right = NULL;
}

// Function to insert a node into the binary search tree
void insert() {
    create();
    if (root == NULL) {
        root = New;
    } else {
        cur = root;
        while (cur != New) {
            if (New->data < cur->data) {
                if (cur->left == NULL) {
                    cur->left = New;
                    break;
                } else {
                    cur = cur->left;
                }
            } else if (New->data > cur->data) {
                if (cur->right == NULL) {
                    cur->right = New;
                    break;
                } else {
                    cur = cur->right;
                }
            } else {
                cout << "Duplicate element";
                return;
            }
        }
    }
}

// Recursive function for preorder traversal
void preorder(struct node *cur) {
    if (cur != NULL) {
        cout << cur->data << " -> ";
        preorder(cur->left);
        preorder(cur->right);
    } else {
        return;
    }
}

// Recursive function for postorder traversal
void postorder(struct node *cur) {
    if (cur != NULL) {
        postorder(cur->left);
        postorder(cur->right);
        cout << cur->data << " -> ";
    } else {
        return;
    }
}

// Recursive function for inorder traversal
void inorder(struct node *cur) {
    if (cur != NULL) {
        inorder(cur->left);
        cout << cur->data << " -> ";
        inorder(cur->right);
    } else {
        return;
    }
}

// Main function
int main() {
    int ch, ele;
    while (1) {
        cout << "Menu\n1. Insert\t2. Preorder\t3. Inorder\t4. Postorder\t5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                exit(1);
                break;
            default:
                cout << "Error: Invalid Choice";
        }
    }
    return 0;
}
