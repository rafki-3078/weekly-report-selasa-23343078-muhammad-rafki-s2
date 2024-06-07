#include <stdio.h>

//create by muhammad rafki 23343078

// Definisi struct untuk data mahasiswa
struct Mahasiswa {
    char NIM[15];
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputData(struct Mahasiswa *mhs) {
    printf("Masukkan NIM: ");
    scanf("%s", mhs->NIM);
    
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", mhs->Nama);
    
    printf("Masukkan Tanggal Lahir: ");
    scanf("%s", mhs->TanggalLahir);
    
    printf("Masukkan IPK: ");
    scanf("%f", &mhs->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(const struct Mahasiswa *mhs) {
    printf("NIM: %s\n", mhs->NIM);
    printf("Nama: %s\n", mhs->Nama);
    printf("Tanggal Lahir: %s\n", mhs->TanggalLahir);
    printf("IPK: %.2f\n", mhs->IPK);
}

// Fungsi untuk menampilkan data mahasiswa dengan perulangan
void tampilkanDataDenganPerulangan(const struct Mahasiswa *mhs, int jumlah) {
    for (int i = 0; i < jumlah; ++i) {
        printf("\nData Mahasiswa ke-%d:\n", i + 1);
        tampilkanData(&mhs[i]);
    }
}

int main() {
    // Deklarasi array untuk menyimpan data mahasiswa
    struct Mahasiswa mahasiswa[100];
    
    // Variabel untuk menyimpan jumlah data mahasiswa yang dimasukkan
    int jumlahData = 0;

    // Variabel untuk menyimpan pilihan menu
    int menu;

    do {
        // Menampilkan menu
        printf("\nMenu:\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                // Input data mahasiswa
                inputData(&mahasiswa[jumlahData]);
                jumlahData++; // Menambah jumlah data mahasiswa
                break;
            case 2:
                // Tampilkan data mahasiswa jika ada data yang dimasukkan
                if (jumlahData > 0) {
                    tampilkanDataDenganPerulangan(mahasiswa, jumlahData);
                } else {
                    printf("Belum ada data mahasiswa yang dimasukkan.\n");
                }
                break;
            case 0:
                // Keluar dari program
                printf("Program selesai.\n");
                break;
            default:
                // Pilihan menu tidak valid
                printf("Pilihan menu tidak valid. Silakan coba lagi.\n");
        }
    } while (menu != 0);

    return 0;
}
