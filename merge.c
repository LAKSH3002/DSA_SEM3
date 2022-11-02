#include<stdio.h>
#include<stdlib.h>
void mergesort(int a[],int low,int high);
void printarray(int a[] , int n);
void merge(int a[],int mid,int low,int high);

void mergesort(int a[],int low ,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}
void merge(int a[],int mid,int low,int high)
{
    int i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;  // MISTAKE
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
        b[k]=a[i];
        i++;k++;
        }
        else
        {
            b[k]=a[j];
            j++;k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;j++;
    }
   // printf("RESULT AFTER MERGE SORT IS\n");
    for(int i = low; i<=high;i++)
    {
        a[i]=b[i];
    }
}
void printarray(int *a,int n)
{
for(int i =0; i<n;i++)
{
    printf("%d ",a[i]);
}
printf("\n");
}
int main()
{
int a[] = {9,14,4,8,7,5,6};
int n = 7;
printarray(a,n);
mergesort(a,0,6);
printarray(a,n);
return 0;
}
