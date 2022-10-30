#include<stdio.h>
int main()
{
    int a[] = {23,14,22,19,11,39,65,71,8,41}; // 14,23,22 --> 14,22,23 --> 14,22,19,11,23 --> 
    int i,j, temp;
    for(i=1;i<10;i++) // 1 - repition process.
    {
        for(j=0;j<10-i;j++) // 0 to 8
        {
         if(a[j]>a[j+1]) // 0>1(23,14) 1>2(23,22) 2>3(23,19) 3>4(23,11) 4>5(23,39) 5>6(39,65) 6>7(65,71) 7>8(71>8) 8>9(71,41) 
    {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
    }
        }
    }
    printf("THEREFORE NOW THE SORTED ORDER IN ASCENDING ORDER IS\n");
    for(i=0;i<10;i++)
    {
        printf("%d  ",a[i]);
    }
}