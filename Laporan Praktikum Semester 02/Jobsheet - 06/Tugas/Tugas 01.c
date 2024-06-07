#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur untuk data mahasiswa
typedef struct
{
    char nim[20];
    char nama[50];
    float nilai;
} Mahasiswa;

// Definisi struktur untuk node stack
typedef struct Node
{
    Mahasiswa data;
    struct Node *next;
} Node;

// Definisi struktur untuk stack
typedef struct
{
    Node *top;
} Stack;

// Fungsi untuk membuat node baru
Node *
createNode(Mahasiswa data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk membuat stack kosong
void initializeStack(Stack *stack)
{
    stack->top = NULL;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

// Fungsi untuk menambahkan data mahasiswa ke dalam stack
void push(Stack *stack, Mahasiswa data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Fungsi untuk menghapus data mahasiswa dari stack
Mahasiswa
pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        Mahasiswa emptyMahasiswa = {"", "", 0};
        return emptyMahasiswa;
    }
    Node *temp = stack->top;
    stack->top = stack->top->next;
    Mahasiswa poppedData = temp->data;
    free(temp);
    return poppedData;
}

// Fungsi untuk menampilkan data mahasiswa dalam stack
void display(Stack *stack)
{
    Node *current = stack->top;
    printf("\nData Mahasiswa:\n");
    while (current != NULL)
    {
        printf("NIM: %s\n", current->data.nim);
        printf("Nama: %s\n", current->data.nama);
        printf("Nilai: %.2f\n", current->data.nilai);
        printf("-----------------\n");
        current = current->next;
    }
}

// Fungsi untuk mengurutkan data mahasiswa dalam stack berdasarkan NIM
void sort(Stack *stack)
{
    // Metode pengurutan stack tidak diperlukan, karena akses langsung ke elemen
    // tidak diperbolehkan dalam stack. Jadi, kita harus menyalin data stack ke
    // dalam array, mengurutkan array, dan kemudian menyalin kembali ke stack.
    Mahasiswa arr[100];
    int count = 0;

    // Memasukkan data dari stack ke dalam array
    Node *current = stack->top;
    while (current != NULL)
    {
        arr[count++] = current->data;
        current = current->next;
    }

    // Pengurutan array berdasarkan NIM
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(arr[j].nim, arr[j + 1].nim) > 0)
            {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Memasukkan data dari array ke dalam stack
    initializeStack(stack);
    for (int i = count - 1; i >= 0; i--)
    {
        push(stack, arr[i]);
    }

    printf("Data Mahasiswa berhasil diurutkan berdasarkan NIM.\n");
}

// Fungsi untuk membersihkan stack dari semua node
void clearStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
}

int main()
{
    Stack stack;
    initializeStack(&stack);

    int choice;
    Mahasiswa newMahasiswa;

    while (1)
    {
        printf("\n=================== Menu ===================\n");
        printf("|1. Tambah Data Mahasiswa 		   |\n");
        printf("|2. Hapus Data Mahasiswa                   |\n");
        printf("|3. Tampilkan Data Mahasiswa               |\n");
        printf("|4. Urutkan Data Mahasiswa berdasarkan NIM |\n");
        printf("|5. Keluar                                 |\n");
        printf("============================================\n");
        printf("\nMasukkan pilihan : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nMasukkan NIM : ");
            scanf("%s", newMahasiswa.nim);
            printf("Masukkan Nama : ");
            scanf(" %[^\n]", newMahasiswa.nama);
            printf("Masukkan Nilai : ");
            scanf("%f", &newMahasiswa.nilai);
            push(&stack, newMahasiswa);
            printf("Data mahasiswa berhasil ditambahkan!\n");
            break;
        case 2:
            if (!isEmpty(&stack))
            {
                pop(&stack);
                printf("Data mahasiswa berhasil dihapus!\n");
            }
            else
            {
                printf("Stack kosong, tidak ada data yang dihapus.\n");
            }
            break;
        case 3:
            if (!isEmpty(&stack))
            {
                display(&stack);
            }
            else
            {
                printf("Stack kosong\n");
            }
            break;
        case 4:
            if (!isEmpty(&stack))
            {
                sort(&stack);
            }
            else
            {
                printf("Stack kosong\n");
            }
            break;
        case 5:
            clearStack(&stack);
            printf("Terima kasih! Program selesai.\n");
            exit(0);
        default:
            printf("Pilihan tidak valid. Silakan pilih menu yang sesuai.\n");
        }
    }

    return 0;
}
