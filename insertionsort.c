#include<stdio.h>
void printarray(int *A,int n)
{
    int i;
for(i=0;i<n;i++)
{
    printf("%d  ",A[i]);
}
printf("\n");
}
void insertionsort(int *A,int n)
{
    int i;
    int key,j;
    //loop for passes
for ( i = 1; i <=n-1; i++)
{
    //loop for each pass
    key=A[i];
    j=i-1;
    // loop for each pass
    while(j>=0 && A[j]>key){ // 
         A[j+1] = A[j];
         j--;
         } 
         A[j+1] = key;
}
}
int main()
{
    
// 0  1  2  3  4  5
// 12,54,65,7, 23, 9

// 12 | 54,65,07,23,09 -> i=1,key=54,j=0
// 12 | 54,65,07,23,09 -> 1st pass done

//12,54 | 65,07,23,09 -> i=2 , key=65,j=1
//12,54,65 | 07,23,09 -> 2nd pass done

// 12,54,65 | 07,23,09 -> i=3 key=07,j=2
// 12,54,65 | 65,23,09 -> i=3,key=07,j=1
// 12 54 54| 65,23,09 -> i=3 , key=07,j=1
// 12 12 54| 65,23,09 -> i=3 , key=7,j=-1
// 7,12,54 | 65,23,09 -> i=3,key=7,j=1 -> 3rd pass done


    int A[] = {12,54,65,7,23,9};
    int n = 6;
    printarray(A,n);
    insertionsort(A,n);
    printarray(A,n);
    return 0;
}