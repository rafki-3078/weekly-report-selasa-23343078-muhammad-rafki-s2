#include <stdio.h>
#include <stdlib.h>

// Maksimal jumlah simpul/graf
#define MAX_NODES 100

// Fungsi untuk melakukan Breadth First Search (BFS)
void BFS(int graph[MAX_NODES][MAX_NODES], int start, int n) {
    int visited[MAX_NODES] = {0}; // Array untuk menandai simpul yang sudah dikunjungi
    int queue[MAX_NODES]; // Antrian untuk BFS
    int front = 0, rear = 0; // Variabel untuk mengontrol antrian

    // Tandai simpul awal sebagai sudah dikunjungi dan tambahkan ke antrian
    visited[start] = 1;
    queue[rear++] = start;

    // Selama antrian tidak kosong, lakukan BFS
    while (front != rear) {
        int current = queue[front++]; // Ambil simpul pertama dari antrian
        printf("%d ", current); // Tampilkan simpul yang sedang dikunjungi

        // Telusuri semua simpul yang terhubung dengan simpul saat ini
        for (int i = 0; i < n; i++) {
            // Jika ada sisi yang terhubung dan simpul belum dikunjungi
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1; // Tandai simpul sebagai sudah dikunjungi
                queue[rear++] = i; // Tambahkan simpul ke antrian
            }
        }
    }
}

int main() {
    int n; // Jumlah simpul/graf
    int graph[MAX_NODES][MAX_NODES]; // Matriks ketetanggaan

    printf("Masukkan jumlah simpul/graf: ");
    scanf("%d", &n);

    printf("Masukkan matriks ketetanggaan (0 jika tidak terhubung, 1 jika terhubung):\n");
    // Input matriks ketetanggaan
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startNode; // Simpul awal untuk BFS
    printf("Masukkan simpul awal untuk BFS: ");
    scanf("%d", &startNode);

    printf("Hasil BFS traversal: ");
    BFS(graph, startNode, n);

    return 0;
}
