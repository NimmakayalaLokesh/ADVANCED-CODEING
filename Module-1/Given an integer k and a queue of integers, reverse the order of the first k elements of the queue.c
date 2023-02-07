#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct // structure for queue
{
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue;

// function to create a queue
void create_queue(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// function to add an element to the queue
void enqueue(queue *q, int element)
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue is full");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = element;
    }
}

// function to delete an element from the queue
int dequeue(queue *q)
{
    int element;
    if (q->front == q->rear)
    {
        printf("Queue is empty");
        return 0;
    }
    else
    {
        q->front++;
        element = q->items[q->front];
        return element;
    }
}

// function to reverse the first k elements of the queue
void reverse_k_elements(queue *q, int k)
{
    int i, temp;

    // if k is greater than the size of the queue
    if (k > q->rear + 1)
    {
        printf("k is greater than the size of the queue\n");
    }

    // reversing the elements
    for (i = q->front + 1; i < q->front + k/2 + 1; i++)
    {
        temp = q->items[i];
        q->items[i] = q->items[q->front + k - i + q->front + 1];
        q->items[q->front + k - i + q->front + 1] = temp;
    }
}

// function to display the queue
void display_queue(queue *q)
{
    int i;
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    queue q;

    int k, element;

    create_queue(&q);

    // adding elements to the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Queue before reversing: ");
    display_queue(&q);

    reverse_k_elements(&q, k);

    printf("Queue after reversing: ");
    display_queue(&q);

    return 0;
}

