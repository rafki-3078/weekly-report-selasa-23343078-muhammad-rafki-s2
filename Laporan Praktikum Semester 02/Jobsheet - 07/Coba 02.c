#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void tambah() {
	struct node *ptr;
	int item;

	ptr = (struct node *)malloc(sizeof(struct node)); // Memperbaiki kesalahan pengetikan "struck node" menjadi "struct node"
	if(ptr == NULL) {
		printf("\nOVERFLOW\n");
		return;
	} else {
		printf("\nSilakan masukan elemen yang kamu inginkan: ");
		scanf("%d", &item);
		ptr->data = item;
		ptr->next = NULL; // Memastikan pointer next pada elemen baru diatur ke NULL

		if(front == NULL) { // Jika antrian kosong
			front = rear = ptr;
		} else {
			rear->next = ptr;
			rear = ptr;
		}
		printf("%d ditambahkan\n", item);
	}
}

void hapus() {
	struct node *ptr;
	if(front == NULL) {
		printf("\nUNDERFLOW\n");
		return;
	} else {
		ptr = front;
		front = front->next;
		printf("\n%d dihapus\n", ptr->data);
		free(ptr);
	}
}

void display() {
	struct node *ptr;
	ptr = front;
	if(front == NULL) {
		printf("\nAntrian kosong\n");
	} else {
		printf("\nMenampilkan antrian:\n");
		while(ptr != NULL) {
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main() {
	int menu;
	menu = 0; // Inisialisasi variabel menu
	while(menu != 4) {
		printf("\n==============Queue Menggunakan Linked List==============");
		printf("\n1.Tambah sebuah elemen\n2.Hapus sebuah elemen\n3.Tampilkan Antrian\n4.Keluar\n");
		printf("=========================================================\n");
		printf("\nMasukan pilihanmu? ");
		scanf("%d", &menu);
		switch(menu) {
			case 1:
				tambah();
				break;
			case 2:
				hapus();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Keluar dari program.\n");
				exit(0);
				break;
			default:
				printf("\nMasukan pilihan menu yang sesuai?\n");
		}
	}
	return 0; // Menambahkan return 0 untuk mengindikasikan bahwa program berakhir dengan sukses
}
