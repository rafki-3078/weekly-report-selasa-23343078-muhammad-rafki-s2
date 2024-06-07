#include <stdio.h>
#include <stdlib.h>

#define BENAR 1
#define SALAH 0
#define PENUH 10

struct node
{
    int data;
    struct node *next;
};

typedef struct node node; // Tipe data untuk simpul dalam linked list

struct queue
{
    int count;   // Jumlah elemen dalam antrian
    node *front; // Pointer ke simpul depan antrian
    node *rear;  // Pointer ke simpul belakang antrian
};

typedef struct queue queue;

// Inisialisasi antrian
void inisialisasi(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

// Cek apakah antrian kosong
int isempty(queue *q)
{
    return (q->count == 0);
}

// Menambahkan elemen baru ke dalam antrian
void enqueue(queue *q, int value)
{
    if (q->count < PENUH)
    {
        node *tmp = (node *)malloc(sizeof(node));
        if (tmp == NULL)
        {
            printf("Kegagalan alokasi memori.\n");
            return;
        }
        tmp->data = value;
        tmp->next = NULL;

        if (!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("Antrian penuh\n");
    }
}

// Menghapus elemen dari depan antrian dan mengembalikan nilainya
int dequeue(queue *q)
{
    if (isempty(q))
    {
        printf("Antrian kosong, tidak ada yang bisa di-dequeue.\n");
        return -1;
    }
    node *tmp = q->front;
    int n = tmp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL; // Antrian sekarang kosong
    }
    q->count--;
    free(tmp);
    return n;
}

// Menampilkan isi antrian
void display(node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d -> ", head->data);
        display(head->next);
    }
}

int main()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        printf("Kegagalan alokasi memori.\n");
        return -1;
    }
    inisialisasi(q);

    // Test fungsi enqueue dan dequeue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);

    printf("Queue sebelum proses dequeue:\n");
    display(q->front);

    dequeue(q);
    printf("\nQueue setelah proses dequeue:\n");
    display(q->front);

    // Pembersihan dan keluar
    while (!isempty(q))
    {
        dequeue(q);
    }
    free(q);
    return 0;
}
