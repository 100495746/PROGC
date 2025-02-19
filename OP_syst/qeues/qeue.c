//
// Created by Raúl Armas Seriñá on 7/5/24.
//
// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    //basically head, tail and actual size
    unsigned capacity;
    //maximum size accepted (not actual size)
    int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue*createQueue(unsigned capacity)
        // returns a pouinter to a qeue struct
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    // q->p equivalent to: (*q).p where q is a pointer to a struct

    queue->front = queue->size = 0;
    //start the queue with 0 elems (and 0 is the first position too)

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    // just like a list, if we have 5 elems, the last position is 4
    queue->array = (int*)malloc(
            queue->capacity * sizeof(int));
    //prepare an array allocating needed dynamic memory; array is an int pointer
    //array points to first element memory address
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;

    // remember, (n+1)%k = n until n+1 = k; when n+1 = k it will then give 0 (so points to start)
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver program to test above functions./
int main()
{
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n",
           dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
