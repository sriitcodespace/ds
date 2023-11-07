#include <iostream>
using namespace std;

int rec(int a[20], int ele, int i);
int itr(int a[20], int ele, int n);

int main() {
    int a[20], ele, ch, n, result;
    cout << "Select method: Linear search\n1. Recursion\n2. Iteration: ";
    cin >> ch;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter element to be searched: ";
    cin >> ele;

    switch (ch) {
        case 1:
            result = rec(a, ele, n - 1); 
            break;
        case 2:
            result = itr(a, ele, n); 
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    if (result == 1)
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

int rec(int a[20], int ele, int i) {
    if (i < 0)
        return 0;
    if (a[i] == ele)
        return 1;
    return rec(a, ele, i - 1);
}

int itr(int a[20], int ele, int n) {
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == ele) {
            f = 1;
            break;
        }
    }
    return f;
    
    }

