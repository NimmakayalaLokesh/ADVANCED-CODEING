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


// 2nd model //

#include<stdio.h>
int queue[20];
int stack[20];
int front=-1,rear=-1,top=-1,fronto=-1,rearo=-1;
int n;
int push(int x)
{	
	if(top== n-1)
	printf("\n overflow");
	else
	{
	top++;
	stack[top]=x;
	//printf("\n push %d",stack[top]);
	}
}
int pop()
{	int temp;
	if(top==-1)
	{
	printf("\n underflow");
	return 9999;
	}
	else
	{
	 temp= stack[top];  
	 top--;
	 return temp;
	}
}
void enqueue(int x)
{
   if(front==-1 && rear==-1)
   {
      front=rear=0;
      queue[rear]=x;
   }
   else if(rear== n-1)
   {
       printf("\nThe queue is full\n");
   }
   else
   {
       rear=rear+1;
       queue[rear]=x;
   }
}
int dequeue()
{
    int temp;
    if(front==rear==-1)
    {
        printf("\nthe queue is empty\n");
        return 9999;
    }
    
    else
    {
        //printf("\nthe dequed element is %d",queue[front]);
        temp = queue[front];
        front=front+1;
        n=n+1;
        return temp;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        enqueue(val);
    }
    int k;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        int temp;
        temp=dequeue();
        push(temp);
    }
    for(i=0;i<k;i++)
    {
        int temp=pop();
        enqueue(temp);
    }
    for(i=0;i<(n-k);i++)
    {
       int temp= dequeue();
       enqueue(temp);
    }
    for(i=0;i<n;i++)
    {
        int temp=dequeue();
        printf("%d",temp);
    }
}
