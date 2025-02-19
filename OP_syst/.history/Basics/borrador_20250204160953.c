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
    scanf("%d", &elems);

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


    // we use -> for struct pointers. "current" is a pointer to a struct, so we cant put current.data
    //current points to nodes[0] in the first instance, so current->data means nodes[0].data
    char out[elems*sizeof(char)];
    printf("Node data: ");
    while (current != NULL) {
        printf("%d ", current->data);
        if(current->next){
            printf(" -> ");
        }
        
        current = current->next; // Move to the next node
    }

    struct Node newnode;
    printf("\nEnter new value for new node: ");
    scanf("%d", newnode.data )

    struct Node *nodes = realloc(nodes, (elems+1) * sizeof(struct Node));
    if (nodes == NULL) {
        printf("Memory reallocation failed\n");
        free(nodes);
        return 1;
    }

    free(nodes); // Free the allocated memory

    return 0;

}