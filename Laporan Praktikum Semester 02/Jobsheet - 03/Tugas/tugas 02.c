#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah suatu bilangan adalah prima
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk menghasilkan bilangan prima pertama sampai ke-n
void generatePrimes(int n, int** primeArray, int* size) {
    int count = 0;
    int* primes = *primeArray;

    for (int num = 2; count < n; num++) {
        if (isPrime(num)) {
            // Gunakan realloc untuk mengubah ukuran memori yang dialokasikan
            *primeArray = (int*)realloc(*primeArray, (*size + 1) * sizeof(int));

            if (*primeArray == NULL) {
                printf("Gagal melakukan realokasi memori.\n");
                exit(1);
            }

            primes = *primeArray;
            primes[*size] = num;
            (*size)++;
            count++;
        }
    }
}

int main() {
    int n, m;
    int* primeArray = NULL;
    int size = 0;

    printf("Masukkan nilai n untuk bilangan prima: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukkan n harus lebih besar dari 0.\n");
        return 1;
    }

    printf("Masukkan nilai m untuk alokasi awal memori: ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("Masukkan m harus lebih besar dari 0.\n");
        return 1;
    }

    // Menggunakan malloc untuk mengalokasikan memori awal
    primeArray = (int*)malloc(m * sizeof(int));

    // Pengecekan apakah alokasi memori berhasil
    if (primeArray == NULL) {
        printf("Gagal melakukan alokasi memori.\n");
        return 1;
    }

    // Memanggil fungsi untuk mengisi nilai bilangan prima
    generatePrimes(n, &primeArray, &size);

    // Menampilkan bilangan prima
    printf("Bilangan prima pertama %d:\n", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", primeArray[i]);
    }
    printf("\n");

    // Menggunakan free untuk membebaskan memori yang dialokasikan
    free(primeArray);

    return 0;
}
