#include <iostream>
using namespace std;

int g[20][20], visited[20], n, queue[20], r = -1, f = 0;
char v[] = {'a', 'b', 'c', 'd', 'e'};

void BFS(int start) {
    visited[start] = 1;
    queue[++r] = start;
   
    while (f <= r) {
        int current = queue[f++];
        cout << v[current] << "->";
   
        for (int j = 0; j < n; j++) {
            if (g[current][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                queue[++r] = j;
            }
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

    cout << "BFS Traversal: ";
    BFS(0);
    cout << endl;

 
    }
