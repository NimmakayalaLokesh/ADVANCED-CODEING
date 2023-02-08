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


// 2nd model 

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
    int i,n1;
    scanf("%d",&n);
    n1=n;
    for(i=0;i<n1;i++)
    {
       int val;
       scanf("%d",&val);
       enqueue(val);
    }
    int mid=(n1-1)/2;
    //printf("\n mid %d",mid);
    for(i=0;i<=mid;i++)
    {
        int re=9999;
        re=dequeue();
        push(re);
    }
    //printf("\nTeja\n");
    for(i=0;i<=mid;i++)
    {
        int re;
        re=pop();
        //printf("\n pop re %d",re);
        enqueue(re);
    }
    for(i=0;i<=mid;i++)
    {
        int re=9999;
        re=dequeue();
        //printf("\n after sq %d",re);
        enqueue(re);
    }
    for(i=0;i<=mid;i++)
    {
        int re=dequeue();
        push(re);
    }
    printf("\n");
    for(i=0;i<n1;i++)
    {
        int re;
        if(i%2==0)
        {
            re= pop();
            printf(" %d ",re);
        }
        else{
            re=dequeue();
            printf(" %d ",re);
        }
    }
    
}
