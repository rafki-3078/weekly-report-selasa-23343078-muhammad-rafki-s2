#include <stdio.h>
#define ukuran 6

int queue[ukuran]; // deklarasi array
int front = -1;
int rear = -1;
// fungsi untuk menambahkan elemen pada circular queue
void enqueue(int element)
{
    if (front == -1 && rear == -1) // kondisi untuk mengecek apakah queue kosong
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % ukuran == front) // kondisi untuk mengecek apakah queue penuh
    {
        printf("Antrian telah penuh..\n");
    }
    else
    {
        rear = (rear + 1) % ukuran; // nilai pada rear bertambah
        queue[rear] = element;      // memberikan nilai pada queue pada posisi rear
    }
}
// fungsi untuk menghapus elemen dari queue
void dequeue()
{
    if ((front == -1) && (rear == -1)) // kondisi untuk mengecek apakah queue kosong
    {
        printf("\nQueue belum penuh..\n");
    }
    else if (front == rear)
    {
        printf("\nElemen yang di-dequeue adalah %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nElemen yang di-dequeue adalah %d\n", queue[front]);
        front = (front + 1) % ukuran;
    }
}

// fungsi untuk menampilkan elemen queue
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Kosong !!\n");
    }
    else
    {
        printf("\nElemen pada queue adalah : ");
        do
        {
            printf("%d, ", queue[i]);
            i = (i + 1) % ukuran;
        } while (i != (rear + 1) % ukuran);
        printf("\n");
    }
}

int main()
{
    int menu = 1, x;              // deklarasi variabel
    while (menu < 4 && menu != 0) // looping menggunakan while
    {
        printf("\n===============Circular Queue=============");
        printf("\n1: Tambah sebuah elemen");
        printf("\n2: Hapus sebuah elemen");
        printf("\n3: Tampilkan elemen");
        printf("\n==========================================\n");
        printf("\nMasukan pilihanmu! ");
        scanf("%d", &menu);
        switch(menu)
        {
            case 1:
                printf("Silakan masukan elemen yang ingin kamu tambah: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    }
    return 0;
}
