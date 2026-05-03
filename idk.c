#include <stdio.h>
int main()
{
    int arr[100000], target, size,sum;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    for(int i=0; i<size; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the target: ");
    scanf("%d",&target);

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size && j!=i; j++)
        {
            sum=arr[i]+arr[j];
            if(sum==target)
            {
                printf("%d,%d\n",i,j);
                break;
            }
        }
    }
    return 0;
}