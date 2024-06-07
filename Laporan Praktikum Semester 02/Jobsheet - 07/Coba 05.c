#include <stdio.h>

int ukuran = 0; // Variabel global untuk menyimpan ukuran heap saat ini

// Fungsi untuk menukar dua nilai
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mempertahankan sifat heap dari bawah ke atas
void naik(int array[], int pos) {
    while (pos > 0) {
        int induk = (pos - 1) / 2;
        if (array[induk] >= array[pos])
            break;
        tukar(&array[pos], &array[induk]);
        pos = induk;
    }
}

// Fungsi untuk mempertahankan sifat heap dari atas ke bawah
void menjadikan_heap(int array[], int n, int i) {
    int terbesar = i; // Inisialisasi terbesar sebagai root
    int kiri = 2 * i + 1; // kiri = 2*i + 1
    int kanan = 2 * i + 2; // kanan = 2*i + 2

    // Jika anak kiri lebih besar dari root
    if (kiri < n && array[kiri] > array[terbesar])
        terbesar = kiri;

    // Jika anak kanan lebih besar dari root atau anak kiri
    if (kanan < n && array[kanan] > array[terbesar])
        terbesar = kanan;

    // Jika terbesar bukan root
    if (terbesar != i) {
        tukar(&array[i], &array[terbesar]);
        menjadikan_heap(array, n, terbesar);
    }
}

// Fungsi untuk menambahkan elemen baru ke dalam heap
void sisip(int array[], int newNum) {
    array[ukuran] = newNum; // Tempatkan elemen baru di akhir heap
    naik(array, ukuran); // Naikkan untuk mempertahankan sifat heap
    ukuran++; // Tingkatkan ukuran heap
}

// Fungsi untuk menghapus elemen tertentu dari heap
void hapusElemen(int array[], int num) {
    int i;
    for (i = 0; i < ukuran; i++) {
        if (num == array[i])
            break;
    }
    if (i == ukuran) return; // Jika elemen tidak ditemukan, keluar dari fungsi

    tukar(&array[i], &array[ukuran - 1]); // Pindahkan elemen ke akhir array
    ukuran--; // Kurangi ukuran heap
    if (i < ukuran) {
        naik(array, i); // Coba naik jika nilai baru lebih besar dari induknya
        menjadikan_heap(array, ukuran, i); // Kemudian jadikan heap jika lebih kecil dari anak-anaknya
    }
}

// Fungsi untuk menampilkan isi heap
void tampilkanArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Program utama
int main() {
    int array[10]; // Inisialisasi array dengan kapasitas maksimum 10 elemen
    sisip(array, 3);
    sisip(array, 4);
    sisip(array, 9);
    sisip(array, 5);
    sisip(array, 2);

    printf("Array Heap Maksimum: ");
    tampilkanArray(array, ukuran);

    hapusElemen(array, 4);
    printf("Setelah menghapus elemen 4 : ");
    tampilkanArray(array, ukuran);

    return 0;
}
