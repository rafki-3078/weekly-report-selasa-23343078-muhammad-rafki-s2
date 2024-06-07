#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

// Fungsi untuk menambahkan node di awal
void push(struct Node** head_ref, int new_data) {
	/* 1. alokasikan node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	/* 2. masukkan data */
	new_node->data = new_data;
	/* 3. Buat next dari node baru sebagai head dan prev sebagai NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	/* 4. ubah prev dari node kepala menjadi node baru */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	/* 5. pindahkan head untuk menunjuk ke node baru */
	(*head_ref) = new_node;
}

// Fungsi untuk menambahkan node setelah node tertentu
void insertAfter(struct Node* prev_node, int new_data) {
	/* 1. periksa apakah node sebelumnya adalah NULL */
	if (prev_node == NULL) {
		printf("node sebelumnya tidak boleh NULL");
		return;
	}
	/* 2. alokasikan node baru */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	/* 3. masukkan data */
	new_node->data = new_data;
	/* 4. Buat next dari node baru sebagai next dari prev_node */
	new_node->next = prev_node->next;
	/* 5. Jadikan node baru sebagai next dari prev_node */
	prev_node->next = new_node;
	/* 6. Jadikan prev_node sebagai prev dari node baru */
	new_node->prev = prev_node;
	/* 7. Ubah prev dari next node baru, jika bukan NULL */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

// Fungsi untuk mencetak elemen dari linked list dimulai dari node yang diberikan
void printList(struct Node* node) {
	struct Node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->prev;
	}
}

int main() {
	/* Mulai dengan list kosong */
	struct Node* head = NULL;
	push(&head, 6);
	push(&head, 5);
	push(&head, 2);
	insertAfter(head->next, 5); // Masukkan 5 setelah node kedua
	printf("Created DLL is: ");
	printList(head);
	return 0;
}
