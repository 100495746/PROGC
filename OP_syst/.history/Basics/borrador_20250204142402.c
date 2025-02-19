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
    struct Node *nodes = malloc(elems * sizeof(struct Node)); // Dynamically allocate memory for nodes
     if (nodes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter number of elements: ");
    scanf("%d", elems);
    for(int i=0; i<elems; ++i){
        printf("Enter value %d: ", i+1);
        scanf("%d", &nodes[i].data);
        nodes[i].next
    }
    

    return 0;

}