#include <stdio.h>
#include <string.h>

// Definisi struktur untuk data mahasiswa
struct Mahasiswa {
    int nim;
    char nama[50];
    char ttl[50];
    float ipk;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(struct Mahasiswa arr[], int n) {
    printf("\n=======================================================\n");
    printf("| Data Mahasiswa:                                     |\n");
    printf("=======================================================\n");
    printf("| %-8s | %-20s | %-10s | %-4s |\n", "NIM", "Nama", "TTL", "IPK");
    printf("=======================================================\n");
    for (int i = 0; i < n; i++) {
        printf("| %-8d | %-20s | %-10s | %-4.2f |\n", arr[i].nim, arr[i].nama, arr[i].ttl, arr[i].ipk);
    }
    printf("=======================================================\n");
}

// Fungsi sequential search
int sequentialSearch(struct Mahasiswa arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i].nim == key) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi untuk menghapus data berdasarkan NIM
void hapusData(struct Mahasiswa arr[], int *n, int nim) {
    int index = sequentialSearch(arr, *n, nim);
    if (index != -1) {
        // Geser elemen-elemen di dalam array
        for (int i = index; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--; // Kurangi jumlah data
        printf("Data dengan NIM %d berhasil dihapus.\n", nim);
    } else {
        printf("Data dengan NIM %d tidak ditemukan.\n", nim);
    }
}

int main() {
    struct Mahasiswa mahasiswa[100]; // Asumsikan maksimal 100 data mahasiswa
    int count = 0; // Jumlah data saat ini

    int choice;
    do {
        printf("\n================================\n");
        printf("| Menu :                       |");
        printf("\n================================\n");
        printf("| 1. Input data                |\n");
        printf("| 2. Hapus data                |\n");
        printf("| 3. Tampilkan data            |\n");
        printf("| 4. Cari data berdasarkan NIM |\n");
        printf("| 0. Keluar                    |\n");
        printf("================================\n");
        printf("Pilihan : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input data
                printf("\nInput data mahasiswa:\n");
                printf("NIM  : ");
                scanf("%d", &mahasiswa[count].nim);
                printf("Nama : ");
                scanf(" %[^\n]s", mahasiswa[count].nama); // Input nama dengan spasi
                printf("TTL  : ");
                scanf("%s", mahasiswa[count].ttl);
                printf("IPK  : ");
                scanf("%f", &mahasiswa[count].ipk);
                count++;
                break;
            case 2:
                // Hapus data
                int nimHapus;
                printf("\nMasukkan NIM yang ingin dihapus: ");
                scanf("%d", &nimHapus);
                hapusData(mahasiswa, &count, nimHapus);
                break;
            case 3:
                // Tampilkan data
                tampilkanData(mahasiswa, count);
                break;
            case 4:
                // Cari data berdasarkan NIM
                int searchKey;
                printf("\nMasukkan NIM yang ingin dicari: ");
                scanf("%d", &searchKey);
                int result = sequentialSearch(mahasiswa, count, searchKey);
                if (result != -1) {
                    printf("Data ditemukan:\n");
                    printf("NIM: %d\n", mahasiswa[result].nim);
                    printf("Nama: %s\n", mahasiswa[result].nama);
                    printf("TTL: %s\n", mahasiswa[result].ttl);
                    printf("IPK: %.2f\n", mahasiswa[result].ipk);
                } else {
                    printf("Data tidak ditemukan.\n");
                }
                break;
            case 0:
                // Keluar dari program
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
