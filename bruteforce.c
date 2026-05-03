#include<stdio.h>

int force(char pass[], char fpass[], int index)
{
    printf("%d ",index);
    if(pass[index]==fpass[index])
    {
        printf("\n%c",fpass[index]);
        return;
    }
    fpass[index]+=1;
    force(pass, fpass, index);

    force(pass, fpass, index+1);


}

int main()
{
    char pass[4];
    char bru[]={"aaa"};
    printf("Enter your password: ");
    scanf("%c",&pass);

    force(pass, bru, 0);
}