#include <iostream>
using namespace std;

int g[20][20], visited[20], n;
char v[] = {'a','b','c','d','e'};

void DFS(int start) {
    visited[start] = 1;
    cout << v[start] << "->";
    for (int j = 0; j < n; j++) {
        if (g[start][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter edges: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter value of " << i << " " << j << ": ";
            cin >> g[i][j];
        }
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFS(0);
    return 0;
}
