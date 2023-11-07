#include <iostream>
using namespace std;

void insert(int a[], int n) {
    int temp, f;
    for (int i = 1; i < n; i++) {
        temp = a[i];
        f = i - 1;
        while (f >= 0 && temp < a[f]) {
            a[f + 1] = a[f];
            f--;
        }
        a[f + 1] = temp;
    }
    cout << "Elements after sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;
}

int main() {
    int a[20], n;
    cout << "Enter the number of elements:" << endl;
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insert(a, n); 
    return 0;
}

