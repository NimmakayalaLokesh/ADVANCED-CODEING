#include<stdio.h>
#define MAXSIZE 1000
int stack[MAXSIZE];
int top=-1;
void push(int item)
{
 if (top>=MAXSIZE-1)
 {
  printf("\nstack overflow");
 }
else
 {
  top=top+1;
  stack[top]=item;
 }
}
int pop()
{
 int item;
 if(top<0)
 {
  printf("stack under flow:invalid infix expression");
  getchar();
  exit(1);
 }
else
{
 item=stack[top];
 top=top-1;
 return(item);
}
}
int is_operator(char symbol)
{
 if (symbol=='^'|| symbol=='*'|| symbol=='/'|| symbol=='+'|| symbol=='-')
 {
return 1;
}
else
{
return 0;
}
}
int main()
{
 int i;
 top=-1;
 int test;
 int flag=0;
 printf("enter the number of elements in the array");
 scanf("%d",&test);
 int arr[test];
 printf("enter the elements of the array");
 for(i<0;i<test;i++)
 {
  scanf("%d",&arr[i]);
 }
 int c=arr[0];
 for(i=0;i<test;i++)
 {
  if(arr[i]==c)
  {
   c++;
  }
else
{
flag=1;
}
}
if(flag==0)
{
 printf("the array is consecutive");
}
else
{
 printf("the array is not consecutive");
}
}


