#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node untuk menyimpan data mobil
struct Node {
    char licensePlate[20];
    char brand[50];
    char ownerName[100];
    struct Node* prev;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* createNode(char licensePlate[], char brand[], char ownerName[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->licensePlate, licensePlate);
    strcpy(newNode->brand, brand);
    strcpy(newNode->ownerName, ownerName);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan mobil ke linked list (antrian)
void enqueue(struct Node** headRef, char licensePlate[], char brand[], char ownerName[]) {
    struct Node* newNode = createNode(licensePlate, brand, ownerName);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Fungsi untuk menghapus mobil dari linked list (antrian) berdasarkan nomor plat
void dequeue(struct Node** headRef, char licensePlate[]) {
    struct Node* current = *headRef;
    while (current != NULL) {
        if (strcmp(current->licensePlate, licensePlate) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *headRef = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan.\n", licensePlate);
}

// Fungsi untuk menampilkan semua mobil dalam antrian
void displayQueue(struct Node* head) {
    printf("================================================================================\n");
    printf("|                     Antrian Mobil pada Perparkiran                           |\n");
    printf("================================================================================\n");
    printf("| %-20s | %-20s | %-30s |\n", "Nomor Plat", "Merk", "Nama Pemilik");
    printf("================================================================================\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("| %-20s | %-20s | %-30s |\n", current->licensePlate, current->brand, current->ownerName);
        current = current->next;
    }
}

// Fungsi untuk menghapus semua mobil dari linked list (antrian)
void clearQueue(struct Node** headRef) {
    struct Node* current = *headRef;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *headRef = NULL;
}

int main() {
    struct Node* parkingLot = NULL;
    int choice;
    char licensePlate[20];
    
    do {
        printf("=========================================\n");
        printf("|                 Menu                  |\n");
        printf("=========================================\n");
        printf("| 1. Masukkan mobil ke dalam antrian    |\n");
        printf("| 2. Keluarkan mobil dari antrian       |\n");
        printf("| 3. Tampilkan antrian mobil            |\n");
        printf("| 4. Keluar                             |\n");
        printf("=========================================\n");
        printf("Pilih opsi : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    char brand[50];
                    char ownerName[100];
                    printf("\nMasukkan nomor plat mobil : ");
                    scanf(" %[^\n]s", licensePlate);
                    printf("Masukkan merk mobil : ");
                    scanf(" %[^\n]s", brand);
                    printf("Masukkan nama pemilik mobil : ");
                    scanf(" %[^\n]s", ownerName);
                    enqueue(&parkingLot, licensePlate, brand, ownerName);
                    printf("Mobil telah dimasukkan ke dalam antrian.\n");
                }
                break;
            case 2:
                printf("Masukkan nomor plat mobil yang ingin dikeluarkan: ");
                scanf(" %[^\n]s", licensePlate);
                dequeue(&parkingLot, licensePlate);
                break;
            case 3:
                displayQueue(parkingLot);
                break;
            case 4:
                clearQueue(&parkingLot);
                printf("Terima kasih! Keluar dari program.\n");
                break;
            default:
                printf("Opsi tidak valid. Silakan masukkan opsi yang benar.\n");
        }
    } while (choice != 4);

    return 0;
}

