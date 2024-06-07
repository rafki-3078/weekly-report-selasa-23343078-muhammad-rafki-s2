#include<stdio.h>
#include<stdlib.h>

#define ukuran 5

void tambah();
void hapus();
void display();

int front = -1, rear = -1;
int queue[ukuran];

int main() {
    int pilihan = 0; // Initialize pilihan to avoid using it uninitialized
    while(pilihan != 4) {
        printf("\n===============Main Menu===============");
        printf("\n1.Tambah sebuah elemen\n2.hapus sebuah elemen\n3.Tampilkan antrian\n4.Keluar\n");
        printf("=======================================");
        printf("\nMasukan pilihanmu ?");
        scanf("%d", &pilihan);
        switch(pilihan) {
            case 1:
                tambah();
                break;
            case 2:
                hapus();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nMasukan pilihan yang sesuai?\n");
        }
    }
    return 0; // Added return statement for main function
}

void tambah() {
    int item;
    printf("\nSilahkan Masukkan Elemen yang Kamu Inginkan\n");
    scanf("%d", &item);
    if(rear == ukuran - 1) {
        printf("\nOVERFLOW\n");
        return;
    } else if(front == -1 && rear == -1) { // Fixed logical structure
        front = rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nNilai berhasil ditambahkan\n"); // Corrected message
}

void hapus() {
    if (front == -1 || front > rear) {
        printf("\nUNDERFLOW\n");
        return;
    } else {
        if(front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
        printf("\nNilai berhasil dihapus\n"); // Corrected message
    }
}

void display() {
    if(front == -1) {
        printf("\nAntrian Kosong\n");
    } else {
        printf("\nMenampilkan nilai .....\n");
        for(int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
