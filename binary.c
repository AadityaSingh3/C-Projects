#include <stdio.h>
int main()
{
    int length, num, low, high, mid;

    printf("Enter the length of array: ");
    scanf("%d",&length);

    int arr[length];
    for(int i=0; i<length; i++)
    scanf("%d",&arr[i]);

    printf("Enter the number to search: ");
    scanf("%d",&num);


    low=0; high=length-1;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(num==arr[mid])
        {
            printf("arr[%d]",mid);
            return 0;
        }

        else if(num<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
}