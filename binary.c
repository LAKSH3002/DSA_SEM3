// BFS , DFS traversals , hashing , queue using linked list
// done - stacks and queues using arrays , stacks using linked list , insertion , merge , selction , bubble , quick sort and 
// insertion in linked list.
#include<stdio.h>
#include<stdlib.h>
void linear(int a[],int n);
void binary(int a[],int n);
int main()
{
    
    int choice;
    int a[] = {2,4,6,8,12,13,3,11,18,6};
    int n = 10;
    printf("ENTER ANY PARTICULAR OPTION FROM THE GIVEN OPTIONS\n");
    printf("1.for linear search \n 2 for binary search\n 3.exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        linear(a,n);
        break;
        case 2:
        binary(a,n);
        break;
        case 3:
        exit(0);
        default:
        printf("INVALID INPUTT\n");
    }
}
void linear(int a[],int n)
{
    int no;
    int c = 0;
    printf("ENTER THE VALUE YOU WANT TO SEARCH\n");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==no)
        {
            printf("NUMBER FOUND AT %d position",i++);
            c=c+1;
        }
    }
    if(c==0)
    {
        printf("NUMBER NOT FOUND IN THE DATA\n");
    }
}
void binary(int a[],int n)
{
    int  mid; int val;
    int c = 0;
    int fv = 0;
    int lv = n-1;
    printf("ENTER THE VALUE TO BE SEARCHED\n");
    scanf("%d",&val);
    while(fv<=lv)
    {
        mid = (fv+lv)/2;
        
        if(a[mid]==val)
        printf("NUMBER found att %d",mid+1);

        if(a[mid]<val)
        fv= mid+1;

        else
        lv = mid-1;
    }
}