#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int arr[100];
    int front;
    int rear;
} s1 ;

void enqueue();
void dequeue();
void display();

int main()
{
    s1.front = -1;
    s1.rear = -1;
    int choice;
    printf("QUEUES USSING ARRAYS\n\n");
    do{
    printf("ENTER ANY PARTICULAR OPTION FROM THE GIVEN OPTIONS\n");
    printf("1.Enqueue\n2.Dequeue\n3.display\n4.exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        default:
        printf("INVALID INPUTT\n");
    }
}
while(choice!=4);
}
void enqueue()
{
    int value;
if(s1.rear==100-1)
printf("QUEUE IS FULL , INSERTION NOT POSSIBLE\n");
else {
if(s1.front==-1)
{
printf("ENTER THE VALUE TO BE INSERTED\n");
scanf("%d",&value);
s1.front==s1.front+1;
s1.rear = s1.rear+1;
s1.arr[s1.rear]=value;
}
}
}
void dequeue()
{
    if(s1.front==s1.rear)
    printf("QUEUE IS EMPTY");
    else
    {
        printf("\nDELETED : %d\n",s1.arr[s1.front]);
        s1.front++;
        if(s1.front==s1.rear)
        s1.front=s1.rear=-1;
    }
}
void display()
{
     if(s1.rear == -1)
      printf("\nQueue is Empty!!!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=s1.front; i<=s1.rear; i++)
	  printf("%d\t",s1.arr[i]);
   }
}