#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int stack[100];/* data */
    int top;
}  s1;

void push();
void pop();
void peek();
void display();
int main()
{
    s1.top=-1;
printf("STACKS USING ARRAYS");
printf("  ");
int choice;
do
{
printf("ENTER ANY VALUE FROM THE FOLLOWING THINGS\n");
printf("1.push\n2.pop\n3.peek\n4.display\n5.exit");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
exit(0);
default:
printf("INVALID INPUT");
}}
while(choice!=4);
}
void push()
{
    int n;
if(s1.top==100-1)
printf("STACK OVERFLOW\n");
else
{
printf("ENTER THE VALUE TO BE PUSHED\n");
scanf("%d",&n);
s1.top=s1.top+1;
s1.stack[s1.top]=n;
}
}
void pop()
{
    if(s1.top==-1)
    printf("STACK IS UNDERFLOW\n");
    else{
        printf("ELEMENT has been DELETED\n");
        s1.top=s1.top-1;
    }
}
void peek()
{
if(s1.top==-1)
printf("NO PEEK ELEMENT PRESENT\n");
else
printf("THE TOPMOST ELEMENT IS %d",s1.stack[s1.top]);
}
void display()
{
    if(s1.top == -1)
      printf("\nStack is Empty!!!");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=s1.top; i>=0; i--)
	 printf("%d\n",s1.stack[i]);
   }
}
