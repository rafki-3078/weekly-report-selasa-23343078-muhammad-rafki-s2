#include <stdio.h>
#include <stdlib.h>
// Struktur dari node
struct Node
{
	int data;
	struct Node *next; // Pointer ke node selanjutnya
	struct Node *prev; // Pointer ke node sebelumnya
};
void insertEnd(struct Node **start, int value)
{
	// Jika list kosong, buat satu node tunggal
	// circular dan doubly list
	if (*start == NULL)
	{
		struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	// Jika list tidak kosong
	/* Temukan node terakhir */
	struct Node *last = (*start)->prev;
	// Buat Node secara dinamis
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = value;
	// Start akan menjadi next dari new_node
	new_node->next = *start;
	// Jadikan node baru sebelum start
	(*start)->prev = new_node;
	// Jadikan last sebelum new node
	new_node->prev = last;
	// Jadikan new node setelah last yang lama
	last->next = new_node;
}
void display(struct Node *start)
{
	struct Node *temp = start;
	printf("\nTraversal ke depan \n");
	while (temp->next != start)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	printf("\nTraversal ke belakang \n");
	struct Node *last = start->prev;
	temp = last;
	while (temp->prev != last)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("%d ", temp->data);
}
int main()
{
	/* Mulai dengan list kosong */
	struct Node *start = NULL;
	// Masukkan 5. Sehingga linked list menjadi 5->NULL
	insertEnd(&start, 5);
	insertEnd(&start, 8);
	insertEnd(&start, 9);
	insertEnd(&start, 3);
	printf("Circular doubly linked list yang dibuat adalah: ");
	display(start);
	return 0;
}