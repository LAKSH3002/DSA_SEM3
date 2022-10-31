#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// A linked list node
struct node
{
  int data;
  struct node *next;
  struct node *prev; // self referntial structures
};

struct node *insert_beg(struct node *start, int new_data)
{
  // 1 - memory allocation to the new node
  struct node *new_node = (struct node *)malloc(sizeof(struct node)); // address 1068bb alloted to new node

  // 2 - insert value to the new node
  new_node->data = new_data;

  start->prev = new_node;
  new_node->next = start;
  new_node->prev = NULL;
  start = new_node;
  return start;
}
struct node *insertafter(struct node *start, int data, int val) // PROBLEM // 4 5 6
{
  struct node *ptr, *preptr, *newnode3;
  newnode3 = (struct node *)malloc(sizeof(struct node));
  newnode3->data = data;      
  ptr = start;                              
  while (preptr->data != val) 
  { 
    preptr=ptr;
    ptr = ptr->next;
  }
  newnode3->next = preptr->next;
  preptr->next = newnode3;
  newnode3 = ptr->prev;
  return start;
}
struct node *insert_end(struct node *start, int new_data)
{

  // 1 - memory allocation to the new node
  struct node *new_node2 = (struct node *)malloc(sizeof(struct node));
  struct node *ptr = start; // THIS WAS THE LINE BECAUSE OF WHICH THE PROGRAM DIDNT RUN , STILL DONT KNOW WHAT HAPPENED

  // 2 -  adding data to the new node created
  new_node2->data = new_data;
  ptr = start;
  while(ptr->next!=NULL)
  {
    ptr = ptr->next;
  }
  ptr->next=new_node2;
  new_node2->prev = ptr;
  new_node2 ->next = NULL;
  return start;
}
struct node *delete_beg(struct node *start)
{
  struct node *ptr; // this points to start
  ptr = start;
  start = start->next;
  start->prev = NULL;
  free(ptr);
return start;
}
struct node *delete_end(struct node *start)
{
  struct node *ptr, *preptr;
  ptr = start;
  while (ptr->next != NULL)
  {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = NULL;
  free(ptr);
   return start;
}
struct node *delete_node(struct node *start)
{
  struct node *ptr, *preptr;
  int val;
  printf("ENTER THE VALUE OF THE NODE TO BE DELETED\n");
  scanf("%d", &val);
  ptr = start;
  if (ptr->data == val)
  {
    start = delete_beg(start);
    return start;
  }
  else
  {
    while (ptr->data != val)
    {
      preptr = ptr;
      ptr = ptr->next;
    }
   preptr->next = ptr->next;
   ptr->next->prev = preptr;
   free(ptr);
   return start;
  }
}
void printList(struct node *n)
{
  if(n==NULL){
    printf("LINKED LIST IS EMPTY\n");
  }
  while (n != NULL)
  {
    printf(" %d <--> ", n->data);
    n = n->next;
  }
  printf("\n");
  printf("\n");
}
int main()
{
  int val1, val2, val3;
  struct node *start = NULL;
  struct node *second = NULL;
  struct node *third = NULL;

  start = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  start->data = 4;
  start->next = second;

  second->data = 5;
  second->next = third;

  third->data = 6;
  third->next = NULL;

  int c, num, no, n, val, number;
  printf("A LINKED LIST ALREADY EXISTS\n");
  printf("YOU CAN INSERT/DELETE ANY VALUE TO IT\n");
  printf("THE FOLLOWING ARE THE OPTIONS AVAILABLE TO YOU\n");
  do
  {
    printf("ENTER 1 TO INSERT AT THE BEGINNING\n");
    printf("ENTER 2 TO INSERT AFTER A NODE\n");
    printf("ENTER 3 TO INSERT AT THE END\n");
    printf("ENTER 4 TO DELETE A NODE AT THE BEGINNING\n");
    printf("ENTER 5 TO DELETE A NODE AT THE END\n");
    printf("ENTER 6 TO DELETE A NODE A PARTICULAR NODE\n");
    printf("ENTER 7 TO PRINT THE LIST\n");
    printf("ENTER 8 TO EXIT\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
      // int num;
      printf("ENTER THE VALUE TO BE INSERTED AT THE FRONT\n");
      scanf("%d", &num);
      start = insert_beg(start, num);
      break;
    case 2:
      // int n;
      printf("ENTER THE VALUE TO BE INSERTED AFTER A NODE\n");
      scanf("%d", &n);
      printf("ENTER THE VALUE OF THE NODE AFTER WHICH YOU WANT TO ADD THIS NEW NODE\n");
      scanf("%d", &val);
      start = insertafter(start, n, val);
      break;
    case 3:
      // int no;
      printf("ENTER THE VALUE TO BE INSERTED AT THE END\n");
      scanf("%d", &no);
      start = insert_end(start, no);
      break;
    case 4:
      start = delete_beg(start);
      break;
      case 5:
      start = delete_end(start);
      break;
      case 6:
     start =  delete_node(start);
      break;
       case 7:
      printf("THEREFORE THE LINKED LIST GENERATED IS\n");
      printList(start);
      break;
      case 8:
      exit(0);
      break;
    default:
      printf("INVALID INPUT\n");
    }
  } while (c != 9);

  return 0;
}