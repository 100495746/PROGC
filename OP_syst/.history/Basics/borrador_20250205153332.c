#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next; // Pointer to the next node
};

int main() {
    int elems;
    printf("Enter number of elements: ");
    scanf("%d", &elems);

    struct Node *nodes = malloc(elems * sizeof(struct Node)); // Dynamically allocate memory for nodes
    if (nodes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < elems; ++i) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &nodes[i].data);
        nodes[i].next = (i < elems - 1) ? &nodes[i + 1] : NULL; // Point to the next node or NULL if it's the last node
    }

    // Example of using a variable to store an address
    struct Node *current = &nodes[0]; // Start with the first node

    // Traverse and print the linked list
    printf("\nLinked List:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");

    // Add a new node at the end of the list
    int del_value;
    printf("Enter value to delete: ");
    scanf("%d", &del_value);

    // Reallocate memory to accommodate the new node
    struct Node *new_nodes = realloc(nodes, (elems + 1) * sizeof(struct Node));
    if (new_nodes == NULL) {
        printf("Memory reallocation failed\n");
        free(nodes);
        return 1;
    }
    nodes = new_nodes;

    // Initialize the new node


    // Update the next pointer of the previous last node
    if (elems > 0) {
        nodes[elems - 1].next = &nodes[elems];
    }

    // Traverse and print the updated linked list
    current = &nodes[0]; // Start with the first node
    printf("\nUpdated Linked List:\n");
    while (current->data != del_value) {
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");

    free(nodes); // Free the allocated memory

    return 0;
}