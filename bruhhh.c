#include<stdio.h>
int main()
{
    int r1,c1,r2,c2, arr1[10][10], arr2[10][10], sol[10][10];
    printf("Enter row and column of matrix 1: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter row and column of matrix 2: ");
    scanf("%d%d",&r2,&c2);

    if(c1!=r2)
    printf("Invalid matrices");

    else
    {
        printf("enter Matrix 1 elements");
        for(int i=0; i<r1; i++)
        for(int j=0; j<c1; j++)
        scanf("%d",&arr1[i][j]);

        printf("enter Matrix 2 elements");
        for(int i=0; i<r2; i++)
        for(int j=0; j<c2; j++)
        scanf("%d",&arr2[i][j]);



        for(int i=0; i<r1; i++)
        for(int j=0; j<c2; j++)
        {
            sol[i][j];
            for(int k=0; k<c1; k++)
            {
                sol[i][j]+=arr1[i][k]*arr2[k][j];
            }
            printf("\n");
        }
  

        for(int i=0; i<r1; i++)
        {
            for(int j=0; j<c2; j++)
            printf("%d\t",sol[i][j]);
            printf("\n");
        }
    }
}