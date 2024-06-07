#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk double linked list
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// Deklarasi fungsi-fungsi
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_list(struct node *);

int main() {
    struct node *start = NULL; // Node awal double linked list
    int option;

    // Loop menu utama
    do {
        printf("\n\n ======= DOUBLE LINKED LIST =======\n");
        printf("\n 1: Buat Double Linked List");
        printf("\n 2: Tampilkan semua node Double Linked List");
        printf("\n 3: Tambah node di awal Double Linked List");
        printf("\n 4: Tambah node di akhir Double Linked List");
        printf("\n 5: Hapus node di awal Double Linked List");
        printf("\n 6: Hapus node di akhir Double Linked List");
        printf("\n 7: Hapus semua node Double Linked List");
        printf("\n 8: Keluar dari Program");
        printf("\n\n Masukkan pilihan menu : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                system("cls");
                start = create_ll(start);
                printf("\n DOUBLE LINKED LIST CREATED");
                break;
            case 2:
                system("cls");
                start = display(start);
                break;
            case 3:
                system("cls");
                start = insert_beg(start);
                break;
            case 4:
                system("cls");
                start = insert_end(start);
                break;
            case 5:
                system("cls");
                start = delete_beg(start);
                break;
            case 6:
                system("cls");
                start = delete_end(start);
                break;
            case 7:
                start = delete_list(start);
                printf("\n DOUBLE LINKED LIST DELETED");
                break;
        }
    } while(option != 8);

    return 0;
}

// Fungsi untuk membuat double linked list
struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\n Tekan 0 untuk berhenti input data");
    printf("\n Masukkan data : ");
    scanf("%d", &num);

    while(num != 0) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;

        if(start == NULL) {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
        } else {
            ptr = start;

            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }

        printf(" Masukkan data berikutnya : ");
        scanf("%d", &num);
    }

    return start;
}

// Fungsi untuk menampilkan double linked list
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;

    printf(" DATA DOUBLE LINKED LIST \n\n");

    while(ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }

    return start;
}

// Fungsi untuk menambah node di awal double linked list
struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;

    printf(" TAMBAH DATA DI AWAL \n\n");
    printf("\n Masukkan data : ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if(start == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
    } else {
        new_node->next = start;
        start->prev = new_node;
    }

    start = new_node;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

// Fungsi untuk menambah node di akhir double linked list
struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;

    printf(" TAMBAH DATA DI AKHIR \n\n");
    printf("\n Masukkan data : ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if(start == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        start = new_node;
    } else {
        ptr = start;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = NULL;
    }

    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

// Fungsi untuk menghapus node di awal double linked list
struct node *delete_beg(struct node *start) {
    if(start == NULL) {
        printf("\n DOUBLE LINKED LIST KOSONG! \n");
        return start;
    }

    struct node *ptr = start;
    start = start->next;

    if(start != NULL)
        start->prev = NULL;

    free(ptr);
    printf("\n DATA AWAL BERHASIL DIHAPUS! \n");

    return start;
}

// Fungsi untuk menghapus node di akhir double linked list
struct node *delete_end(struct node *start) {
    if(start == NULL) {
        printf("\n DOUBLE LINKED LIST KOSONG! \n");
        return start;
    }

    struct node *ptr = start;

    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev != NULL)
        ptr->prev->next = NULL;

    free(ptr);
    printf("\n DATA AKHIR BERHASIL DIHAPUS! \n");

    return start;
}

// Fungsi untuk menghapus semua node double linked list
struct node *delete_list(struct node *start) {
    while(start != NULL)
        start = delete_beg(start);

    return start;
}
