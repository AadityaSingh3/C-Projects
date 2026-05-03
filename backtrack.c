#include <stdio.h>

int arrcheck(int arr[], int len)
{
    int n=0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len&&j!=i; j++)
        if(arr[i]==arr[j])
        n++;
    }
    if(n>0)
    return 0;
    else
    return 1;
}

/*
int fill(int arr[])
{
    for(int i=0; i<9; i++)
    {
        if(arr[i]==0)
        arr[i]=1;
    }
}
*/

void solve(int arr[], int n )
{
    if(n==8)
    {
        for(int i=0; i<9; i++)
        printf("%d",arr[i]);
        return;
    }

    if(arr[n]==0)
    {
        arr[n]++;
    }
}

int main()
{
    int arr[10];
    printf("Enter an array: ");
    for(int i=0; i<9; i++)
    scanf("%d",&arr[i]);
    //fill(arr);

}