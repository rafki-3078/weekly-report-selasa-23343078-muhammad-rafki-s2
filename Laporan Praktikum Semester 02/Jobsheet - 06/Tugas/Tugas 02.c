#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Definisi struktur untuk node stack
typedef struct Node {
	char data;
	struct Node* next;
} Node;

// Definisi struktur untuk stack
typedef struct {
	Node* top;
} Stack;

// Fungsi untuk membuat node baru
Node* createNode(char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Fungsi untuk membuat stack kosong
void initializeStack(Stack* stack) {
	stack->top = NULL;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(Stack* stack) {
	return stack->top == NULL;
}

// Fungsi untuk menambahkan karakter ke dalam stack
void push(Stack* stack, char data) {
	Node* newNode = createNode(data);
	newNode->next = stack->top;
	stack->top = newNode;
}

// Fungsi untuk menghapus karakter dari stack
char pop(Stack* stack) {
	if (isEmpty(stack)) {
		return '\0'; // Karakter null jika stack kosong
	}
	Node* temp = stack->top;
	stack->top = stack->top->next;
	char poppedData = temp->data;
	free(temp);
	return poppedData;
}

// Fungsi untuk membalikkan kata menggunakan stack
void reverseWord(char* word) {
	Stack stack;
	initializeStack(&stack);

	// Push semua karakter dari kata ke dalam stack
	int i;
	for (i = 0; word[i] != '\0'; i++) {
		push(&stack, word[i]);
	}

	// Pop dan cetak karakter dari stack untuk membalikkan kata
	printf("\nKata dibalik: ");
	while (!isEmpty(&stack)) {
		printf("%c", pop(&stack));
	}
	printf("\n");
}

int main() {
	char kata[MAX_LENGTH];
	int choice;

	while (1) {
		printf("\nMenu:\n");
		printf("1. Input Kata\n");
		printf("2. Balik Kata\n");
		printf("3. Exit\n");
		printf("Masukkan pilihan: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Masukkan kata: ");
				scanf(" %[^\n]s", kata);
				break;
			case 2:
				if (strlen(kata) > 0) {
					reverseWord(kata);
				} else {
					printf("Kata belum diinputkan.\n");
				}
				break;
			case 3:
				printf("Terima kasih! Program selesai.\n");
				exit(0);
			default:
				printf("Pilihan tidak valid. Silakan pilih menu yang sesuai.\n");
		}
	}

	return 0;
}
