#include<stdio.h>

int bubble(int arr[], int size, int sorted[])
{
    int temp;
    for(int i=0; i<size-1; i++)
    for(int j=0; j<size-1-i; j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }

    printf("\nSorted Array: ");
    for(int i=0; i<size; i++)
    {
        sorted[i]=arr[i];
        printf("%d ",sorted[i]);
    }
}

int binary(int arr[50], int search, int size)
{
    int low=0, high=size-1, mid;
    while(low<high)
    {
        mid=(low+high)/2;

        if(arr[mid]==search)
        {
            printf("Found at arr[%d]",mid);
            return 0;
        }

        else if(arr[mid]<search)
        low=mid+1;

        else
        high=mid-1;
    }
}
int main()
{
    int arr[50], sorted[50], size, search;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    for(int i=0; i<size; i++)
    {
        printf("Enter element number: ");
        scanf("%d",&arr[i]);    
    }

    bubble(arr, size, sorted);

    printf("\nEnter the number to search: ");
    scanf("%d",&search);

    binary(arr, search, size);
}