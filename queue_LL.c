#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  

struct node *front;  
struct node *rear;   

void enqueue()  
{  
    struct node *newnode;  
    int item;   
      
    newnode = (struct node *) malloc (sizeof(struct node));  
    if(newnode== NULL)  
    {  
        printf("\n QUEUE OVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        newnode -> data = item;  
        if(front == NULL)  
        {  
            front = newnode;  
            rear = newnode;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = newnode;  
            rear = newnode;  
            newnode->next = NULL;  
        }  
    }  
}     
void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nQUEUE UNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {  
        while(ptr != NULL)   
        {  
            printf("%d ----",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
int main ()  
{  
    int choice;   
    while(choice != 4)   
    {       
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
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
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
    return 0;
} 