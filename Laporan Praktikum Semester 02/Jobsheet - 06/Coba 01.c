#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan stack
struct Stack {
	int atas;
	unsigned kapasitas;
	int* array;
};

// Fungsi untuk membuat stack berdasarkan kapasitas yang diberikan.
struct Stack* buatStack(unsigned kapasitas) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->kapasitas = kapasitas;
	stack->atas = -1;
	stack->array = (int*)malloc(stack->kapasitas * sizeof(int));
	return stack;
}

// Cek apakah stack penuh
int isFull(struct Stack* stack) {
	return stack->atas == stack->kapasitas - 1;
}

// Cek apakah stack kosong
int isEmpty(struct Stack* stack) {
	return stack->atas == -1;
}

// Menambahkan elemen ke stack (push)
void push(struct Stack* stack, int item) {
	if (isFull(stack)) {
		printf("Stack penuh, tidak bisa menambahkan %d\n", item);
		return;
	}
	stack->array[++stack->atas] = item;
	printf("%d ditambahkan ke stack\n", item);
}

// Menghapus elemen dari stack (pop)
int pop(struct Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack kosong\n");
		return INT_MIN;
	}
	return stack->array[stack->atas--];
}

// Mendapatkan elemen teratas dari stack tanpa menghapusnya (peek)
int peek(struct Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack kosong\n");
		return INT_MIN;
	}
	return stack->array[stack->atas];
}

// Program utama untuk menguji fungsi-fungsi di atas
int main() {
	struct Stack* stack = buatStack(100);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printf("%d dihapus dari stack\n", pop(stack));
	printf("%d adalah elemen teratas dari stack\n", peek(stack));

	return 0;
}
