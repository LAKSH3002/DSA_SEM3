#include<stdio.h>
int main()
{
   int a[]={30,10,45,55,25,60};
    // SELECTION SORTING - 1 METHOD
    int i,j,temp;
    for(i=0;i<6;i++)// 0 1 2 3 4 5
    {
        for(j=i+1;j<6;j++)// 1  2  3  4  5  6
        {
            if(a[i]<a[j]) // 0>1 0>2 0>3 0>4 0>5   1>2 1>3 1>4 1>5   2>3 2>4 2>5    3>4 3>5   4>5
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<6;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
    }

// 2ND METHOD
  /*  for(i=0;i<6;i++)
    {
           if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
    }
     for(i=0;i<6;i++)
    {
        printf("%d ",a[i]);
    }
}*/