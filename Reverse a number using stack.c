#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
int stack[MAXSIZE];
int top = -1;

int isEmpty()
{
		if(top == -1)
				return 1;
		else
				return 0;
}

int isFull()
{
		if(top == MAXSIZE)
				return 1;
		else
				return 0;
}

int peek()
{
		return stack[top];
}

void push(int e)
{
		if(!isFull())
		{
				top++;
				stack[top] = e;
		}
		else
		{
				printf("Stack is Full\n");
		}
}

int pop()
{
		int d;
		if(!isEmpty())
		{
				d = stack[top];
				top--;
				return d;
		}
		else
		{
				printf("Stack is Empty\n");
		}
		return 0;
}

int main()
{
		int num, rem;
		printf("Enter the number: ");
		scanf("%d", &num);
		while(num!=0)
		{
				rem = num%10;
				push(rem);
				num = num/10;
		}
		printf("Reversed Number is: ");
		while(!isEmpty())
		{
				int d = pop();
				printf("%d",d);
		}
		printf("\n");
		return 0;
}
