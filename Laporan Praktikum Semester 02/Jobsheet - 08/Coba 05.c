#include <stdio.h>
#define MAX 7

int intArray[MAX] = {4, 6, 3, 2, 1, 9, 7};

// Fungsi untuk mencetak garis pemisah
void printline(int count) {
    for (int i = 0; i < count; i++) {
        printf("=");
    }
    printf("\n");
}

// Fungsi untuk menampilkan array
void display() {
    printf("[");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

// Fungsi untuk melakukan insertion sort
void insertionSort() {
    int valueToInsert, holePosition;

    for (int i = 1; i < MAX; i++) {  // Mulai dari 1 karena anggap elemen pertama sudah tersortir
        valueToInsert = intArray[i];  // Menyimpan nilai yang akan disisipkan
        holePosition = i;

        // Mencari posisi untuk menyisipkan elemen
        while (holePosition > 0 && intArray[holePosition - 1] > valueToInsert) {
            intArray[holePosition] = intArray[holePosition - 1];  // Menggeser elemen ke kanan
            holePosition--;
            printf("Item moved: %d\n", intArray[holePosition]);
        }

        if (holePosition != i) {
            printf("Item inserted: %d, at position: %d\n", valueToInsert, holePosition);
        }

        intArray[holePosition] = valueToInsert;  // Menyisipkan elemen di posisi yang benar
        printf("Iteration %d#: ", i);
        display();  // Menampilkan array setelah setiap iterasi
    }
}

int main() {
    printf("Original Array: ");
    display();  // Menampilkan array sebelum sort
    printline(50);

    insertionSort();

    printf("Sorted Array: ");
    display();  // Menampilkan array setelah sort
    return 0;
}
