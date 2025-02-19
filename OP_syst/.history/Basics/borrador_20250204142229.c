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

    printf("Enter number of elements: %d", elems);
    struct Node node[elems];
    for(int i=0; i<elems; ++i){
        printf("Enter value %d: ", i+1);
        scanf("%d", node[i].data);
        next = &node[i+1]
    }
    

    return 0;

}