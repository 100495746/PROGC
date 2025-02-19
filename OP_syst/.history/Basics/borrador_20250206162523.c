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
    current = &nodes[0];

   

   

    // Find the node to delete and shift elements
    int current_max = -1;
    for (int i = 0; i < elems; ++i) {
        if (nodes[i].data == number) {
            
            printf("Value found at position %d", i);
        }

    }
    
    if(index==-1){
        printf("Value not found in the list\n");

    }
    
    free(nodes); // Free the allocated memory

    return 0;
}
