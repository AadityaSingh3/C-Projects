#include<stdio.h>

int main()
{
    int arr[3][3], n;
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            arr[row][col]=col;
            printf("%d",arr[row][col]);

        }
        printf("");
    }
}