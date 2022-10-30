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


void insert_beg(struct node **start, int new_data)
{
  // 1 - memory allocation to the new node
  struct node *new_node = (struct node *)malloc(sizeof(struct node)); // address 1068bb alloted to new node

  // 2 - insert value to the new node
  new_node->data = new_data;

  // 3 - make next of new node as head
  new_node->next = (*start); 

  // 4  - move the head to point to the new node
  (*start) = new_node; 
}
struct node *insertafter(struct node *start, int data, int val) // PROBLEM
{
  struct node *ptr, *preptr, *newnode3;
  newnode3 = (struct node *)malloc(sizeof(struct node));
  newnode3->data = data;      // 7 // 3 4 5 // after 4
  ptr = start;                // 3
  preptr = ptr;               // preptr = 3
  while (preptr->data != val) // 3!=3 true
  {
    preptr = ptr; // 3
    ptr = ptr->next;
  }
  preptr->next = newnode3;
  newnode3->next = ptr;
  return start;
}
void insert_end(struct node **start, int new_data)
{

  // 1 - memory allocation to the new node
  struct node *new_node2 = (struct node *)malloc(sizeof(struct node));
  struct node *ptr = *start; // THIS WAS THE LINE BECAUSE OF WHICH THE PROGRAM DIDNT RUN , STILL DONT KNOW WHAT HAPPENED

  // 2 -  adding data to the new node created
  new_node2->data = new_data;

  // 3-  make next of the new node null
  new_node2->next = NULL;

  // 4 - if the list is empty then the new node is the first as well as the last element
  if (*start == NULL)
  {
    *start = new_node2;
    return;
  }
  //  5 - traverse the list till we dont get the next of any node pointing to null
  while (ptr->next != NULL)
    ptr = ptr->next;

  // 6 - adding the node to the end
  ptr->next = new_node2;
}
struct node *delete_beg(struct node *start)
{
  struct node *ptr; // this points to start
  ptr = start;
  start = start->next;
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
    printf(" %d --> ", n->data);
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
      insert_beg(&start, num);
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
      insert_end(&start, no);
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

// linked list - creation and insertion
// LINKED LUST - DELTION LEFT
// quick and radix sort