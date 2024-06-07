#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int n, int* fibonacciArray) {
    if (n <= 0) {
        printf("Masukkan n harus lebih besar dari 0.\n");
        return;
    }

    fibonacciArray[0] = 0;
    if (n > 1) {
        fibonacciArray[1] = 1;
        for (int i = 2; i < n; i++) {
            fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
        }
    }
}

int main() {
    int n;

    printf("Masukkan nilai n untuk deret Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukkan n harus lebih besar dari 0.\n");
        return 1;
    }

    // Menggunakan malloc untuk mengalokasikan memori
    int* fibonacciArray = (int*)malloc(n * sizeof(int));

    // Pengecekan apakah alokasi memori berhasil
    if (fibonacciArray == NULL) {
        printf("Gagal melakukan alokasi memori.\n");
        return 1;
    }

    // Memanggil fungsi untuk mengisi nilai deret Fibonacci
    generateFibonacci(n, fibonacciArray);

    // Menampilkan deret Fibonacci
    printf("Deret Fibonacci pertama %d angka:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacciArray[i]);
    }
    printf("\n");

    // Menggunakan free untuk membebaskan memori yang dialokasikan
    free(fibonacciArray);

    return 0;
}
