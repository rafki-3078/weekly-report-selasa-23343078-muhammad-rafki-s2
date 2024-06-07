#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return; 
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data) {
    if (next_node == NULL) {
        printf("The given next node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return; 
    }

    new_node->data = new_data;
    new_node->prev = next_node->prev;
    new_node->next = next_node;

    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head_ref) = new_node;

    next_node->prev = new_node;
}

void printList(struct Node* node) {
    struct Node* last = NULL;
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

void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

int main() {
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
    insertBefore(&head, head->next, 8);

    printf("Created Doubly Linked List is: ");
    printList(head);

    freeList(&head); 

    return 0;
}
