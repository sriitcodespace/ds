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
    int values[] = {1, 5, 6, 55, 456, 62, 36, 25};
    int size = sizeof(values) / sizeof(values[0]);

    root = createNode(values[0]);
    for (int i = 1; i < size; i++) {
        insert(root, values[i]);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

