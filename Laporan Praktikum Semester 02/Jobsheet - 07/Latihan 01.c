#include <stdio.h>
#define ukuran 5

void enQueue(int);
void deQueue();
void tampilkan();

int items[ukuran], depan = -1, belakang = -1;

int main()
{

    deQueue();
    enQueue(7);
    enQueue(8);
    enQueue(3);
    enQueue(4);
    enQueue(9);
    enQueue(4);
    tampilkan();
    deQueue();
    tampilkan();
    return 0;
}

void enQueue(int value)
{
    if (belakang == ukuran - 1)
        printf("\nQueue telah penuh!\n");
    else
    {
        if (depan == -1)
            depan = 0;
        belakang++;
        items[belakang] = value;
        printf("\nNilai ditambahkan -> %d\n", value);
    }
}

void deQueue()
{
    if (depan == -1)
        printf("\nQueue kosong!!");
    else
    {
        printf("\nNilai dihapus adalah : %d\n", items[depan]);
        depan++;
        if (depan > belakang)
            depan = belakang = -1;
    }
}

void tampilkan()
{
    if (belakang == -1)
        printf("\nQueue kosong!!!");
    else
    {
        int i;
        printf("\nElemen pada Queue adalah:\n");
        for (i = depan; i <= belakang; i++)
            printf("%d\t", items[i]);
    }
}
