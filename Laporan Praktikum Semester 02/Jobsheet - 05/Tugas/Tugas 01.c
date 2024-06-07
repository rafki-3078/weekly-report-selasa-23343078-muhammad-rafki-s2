#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node untuk menyimpan data buku
struct Node {
    char title[100];
    char author[100];
    int year;
    struct Node* prev;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* createNode(char title[], char author[], int year) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->year = year;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan buku ke linked list
void addBook(struct Node** headRef, char title[], char author[], int year) {
    struct Node* newNode = createNode(title, author, year);
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

// Fungsi untuk menghapus buku dari linked list berdasarkan judul
void removeBook(struct Node** headRef, char title[]) {
    struct Node* current = *headRef;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
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
    printf("Buku dengan judul '%s' tidak ditemukan.\n", title);
}

// Fungsi untuk menampilkan semua buku dalam perpustakaan
void displayBooks(struct Node* head) {
    printf("=========================================\n");
    printf("|          Daftar Buku Perpustakaan     |\n");
    printf("=========================================\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("| Judul: %-30s |\n", current->title);
        printf("| Pengarang: %-26s |\n", current->author);
        printf("| Tahun: %-30d |\n", current->year);
        printf("=========================================\n");
        current = current->next;
    }
}

// Fungsi untuk menghapus semua buku dari linked list
void clearLibrary(struct Node** headRef) {
    struct Node* current = *headRef;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *headRef = NULL;
}

// Fungsi untuk menukar data dua buku
void swap(struct Node* a, struct Node* b) {
    char tempTitle[100];
    char tempAuthor[100];
    int tempYear;

    strcpy(tempTitle, a->title);
    strcpy(tempAuthor, a->author);
    tempYear = a->year;

    strcpy(a->title, b->title);
    strcpy(a->author, b->author);
    a->year = b->year;

    strcpy(b->title, tempTitle);
    strcpy(b->author, tempAuthor);
    b->year = tempYear;
}

// Fungsi untuk mengurutkan linked list berdasarkan judul buku
void sortBooksByTitle(struct Node* head) {
    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    // Return if linked list is empty
    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (strcmp(current->title, current->next->title) > 0) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Input data buku\n");
    printf("2. Hapus data buku\n");
    printf("3. Tampilkan data buku\n");
    printf("4. Urutkan data buku berdasarkan judul\n");
    printf("5. Keluar\n");
}

int main() {
    struct Node* library = NULL;
    int choice;
    char title[100];
    
    do {
        displayMenu();
        printf("\nPilih opsi: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    char author[100];
                    int year;
                    printf("Masukkan judul buku: ");
                    scanf(" %[^\n]s", title);
                    printf("Masukkan nama pengarang: ");
                    scanf(" %[^\n]s", author);
                    printf("Masukkan tahun terbit: ");
                    scanf("%d", &year);
                    addBook(&library, title, author, year);
                    printf("Buku telah ditambahkan.\n");
                }
                break;
            case 2:
                printf("Masukkan judul buku yang ingin dihapus: ");
                scanf(" %[^\n]s", title);
                removeBook(&library, title);
                break;
            case 3:
                displayBooks(library);
                break;
            case 4:
                sortBooksByTitle(library);
                printf("Buku telah diurutkan berdasarkan judul.\n");
                break;
            case 5:
                clearLibrary(&library);
                printf("Terima kasih! Keluar dari program.\n");
                break;
            default:
                printf("Opsi tidak valid. Silakan masukkan opsi yang benar.\n");
        }
    } while (choice != 5);

    return 0;
}
