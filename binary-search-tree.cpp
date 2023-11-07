#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = nullptr;

struct node *createNode(int value) {
    struct node *newNode = new node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insert(struct node *root, int value) {
    if (root == nullptr) {
        root = createNode(value);
        if (::root == nullptr) {
            ::root = root;
        }
    } else {
        if (value <= root->data) {
            if (root->left == nullptr) {
                root->left = createNode(value);
            } else {
                insert(root->left, value);
            }
        } else {
            if (root->right == nullptr) {
                root->right = createNode(value);
            } else {
                insert(root->right, value);
            }
        }
    }
}

void inorderTraversal(struct node *root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int ch, ele;
    while (true) {
        cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> ele;
                insert(root, ele);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}

