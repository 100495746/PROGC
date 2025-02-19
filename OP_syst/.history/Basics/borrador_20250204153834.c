#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
linked lists:
✅ Can grow dynamically (no fixed size).
✅ Allow efficient insertion/deletion (no shifting elements).
❌ Use more memory (extra pointer in each node)
*/

struct Node{
    int data;
    struct Node *next; // Pointer to the next node
};


int main() {
    int elems;
    

    printf("Enter number of elements: ");
    scanf("%d", elems);

    struct Node *nodes = malloc(elems * sizeof(struct Node)); // Dynamically allocate memory for nodes
    if (nodes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for(int i=0; i<elems; ++i){
        printf("Enter value %d: ", i+1);
        scanf("%d", &nodes[i].data);
        nodes[i].next =  (i < elems - 1) ? &nodes[i + 1] : NULL;
    }
    
    // Example of using a variable to store an address
    struct Node *current = &nodes[0]; // Start with the first node

    // Traverse and print the linked list


    // we use -> for struct pointers. 
    while (current != NULL) {
        printf("Node data: %d\n", current->data);
        current = current->next; // Move to the next node
    }

    free(nodes); // Free the allocated memory

    return 0;

}