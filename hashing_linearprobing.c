#include <stdio.h>
#include <stdlib.h>
void insert(int arr[], int n)
{
    int num;
    printf("Number to be inserted: ");
    scanf("%d", &num);
    int h_index = num % n;
    int check = 0;
    if (arr[h_index] == -1)
    {
        arr[h_index] = num;
        return;
    }
    //if the index is already occupied
    // so we declare the new index
    for (int j = 0; j < n; j++)
    {
        int h2_index = (h_index + j) % n;

        if (arr[h2_index] == -1)
        {
            arr[h2_index]=num;
            check = 1;
            break;
        }
    }
    if (check == 0)
    {
        printf("Arr Full\n");
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("THE NUMBER OF ELEMENTS IN THE ARRAYS / SIZE OF ARRAY : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    int val;
    printf("Welcome to Linear Hashing Operations\n");
    do
    {
        int choice;
         printf("\n1.Insert \t2.Display \t3.Exit  \nEnter the choice: ");
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(arr, n);
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("INVALID INPUT\n");
            break;
        }
    } while (1);

    return 0;
}