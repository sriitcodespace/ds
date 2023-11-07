#include <iostream>
using namespace std;

int rec(int a[], int min, int max, int ele);
int itr(int a[], int n, int ele);

int main() {
    int a[20], ele, ch, n, result;

    cout << "Select method: Binary search\n1. Recursive\n2. Iterative: ";
    cin >> ch;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter element to be searched: ";
    cin >> ele;

    switch (ch) {
        case 1:
            result = rec(a, 0, n - 1, ele);
            break;
        case 2:
            result = itr(a, n, ele);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    if (result != -1)
        cout << "Element found  "<< endl;
    else
        cout << "Element not found." << endl;

    return 0;
}


// Recursive binary search
int rec(int a[], int min, int max, int ele) {
    if (min > max)
        return -1;

    int mid = min + (max - min) / 2;

    if (a[mid] == ele)
        return mid;
    else if (a[mid] < ele)
        return rec(a, mid + 1, max, ele);
    else
        return rec(a, min, mid - 1, ele);
}

// Iterative binary search
int itr(int a[], int n, int ele) {
    int min = 0, max = n - 1;

    while (min <= max) {
        int mid = min + (max - min) / 2;

        if (a[mid] == ele)
            return mid;
        else if (a[mid] < ele)
            min = mid + 1;
        else
            max = mid - 1;
    }

    return -1;
}
