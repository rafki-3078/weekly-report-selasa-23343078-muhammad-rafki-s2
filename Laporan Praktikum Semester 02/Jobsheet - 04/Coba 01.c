#include <stdio.h>
#include <stdlib.h>

// Structure of the node
struct Node {
	int data;
	struct Node *next; 
	struct Node *prev; 
};

void push(struct Node** head_ref, int new_data) {
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	
	(*head_ref) = new_node;
}

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

	struct Node* head = NULL;
	push(&head, 8);
	push(&head, 6);
	push(&head, 4);
	printf("Created DLL is: ");
	printList(head);
	getchar();
	return 0;
}