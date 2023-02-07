#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    int value;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        value = queue[front];
        front++;
        return value;
    }
}

void interleave() {
    int size = (rear - front + 1) / 2;
    int i, j;
    for (i = 0; i < size; i++) {
        int temp = queue[front + i];
        queue[front + i] = queue[front + size + i];
        queue[front + size + i] = temp;
    }
}

int main() {
    int i, num;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &num);
    printf("Enter %d elements: ", num);
    for (i = 0; i < num; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }
    interleave();
    printf("Queue after interleaving:\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}
