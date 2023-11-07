#include <iostream>
using namespace std;

void selectsort(int A[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i) {
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
    cout << "Elements after sorting: \n";
    for (int i = 0; i < n; i++)
        cout << A[i] << "\t";
    cout << endl;
}

int main() {
    int a[20], n, i;
    cout << "Enter the number of elements: \n";
    cin >> n;
    
    cout << "Enter elements: \n";
    for (i = 0; i < n; i++)
        cin >> a[i];
    selectsort(a, n);
    return 0; 
}

