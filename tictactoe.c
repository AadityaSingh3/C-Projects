#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int printmat(int arr[3][3])
{
    int n, col, num=1;
    for(int row=0; row<3; row++)
    {
        printf("|");
        for(col=0; col<3; col++)
        {
            arr[row][col]=num;
            printf("%d|",arr[row][col]);
            num++;
        }
        printf("\n-------\n");
    }
    return 0;
}


int printnewmat(int arr[3][3])
{
    int n, col, num=1;
    for(int row=0; row<3; row++)
    {
        printf("|");
        for(col=0; col<3; col++)
        {
            if(arr[row][col]==-1)
            printf("X|");
            else if(arr[row][col]==-2)
            printf("O|");
            else
            printf(" |");
        }
        printf("\n-------\n");
    }
    return 0;
}


int userinput(int *n, int arr[3][3])
{
    printf("Choose a cell: ");
    scanf("%d",n);
    int row=(*n-1)/3, col=(*n-1)%3;
    if(*n<1 || *n>9)
    {
        printf("\nCell number %d is not in the grid\nTry again: \n",*n);
        return(userinput(n, arr));

    }
    else if(arr[row][col]==-1||arr[row][col]==-2)
    {
        printf("\nPlace Already Taken. Try Again: \n");
        return(userinput(n, arr));
    }
}


int yourmove(int arr[3][3], int *n)
{
    int num=1, temp;
    temp=*n;
    printf("\nYour Move\n");
    for(int row=0; row<3; row++)

        for(int col=0; col<3; col++)
        {
            if(arr[row][col]==-1)
            {
                num++;
            }
            else if(arr[row][col]==-2)
            {
                num++;
            }
            else if(temp==num)
            {
                arr[row][col]=-1;
                num++;
            }
            else
            {
                arr[row][col]=num;
                num++;
            }
        }
    printnewmat(arr);
    return 0;
}

int compmove(int arr[3][3])
{

    printf("\nComputer Move\n");
    while(1)
    {
        int randnum = rand()%9;
        int num=1, placed=0;

        for(int row=0; row<3; row++)
            for(int col=0; col<3; col++)
            {
                if((randnum+1)==num&&arr[row][col]!=-1 &&arr[row][col]!=-2)
                {
                    arr[row][col]=-2;
                    placed=1;
                }
                    num++;
            }
        if(placed)
        break;
    }
    printnewmat(arr);
    return 0;
}

int wincheck(int arr[3][3])
{
    int num,c,h=0,v=0,difficulty=0;


    //horizontal check
    for(int row=0; row<3; row++)
    {
        c=0;
        for(int col=0; col<3; col++)
            for(int col1=0; col1<3 && col1!=col; col1++)
            {
                if(arr[row][col]==arr[row][col1])
                c++;
                if(c==2)
                {
                    h++;
                    if(arr[row][col]==-1)
                    printf("\nYou Win!\n");
                    else if(arr[row][col]==-2)
                    printf("\nYou Lost.\n");
                    else
                    printf("\nIts a Draw\n");
                    return 1;
                }
            }
    }


    //Vertical check
    for(int col=0; col<3; col++)
    {
        c=0;
        for(int row=0; row<3; row++)
            for(int row1=0; row1<3 && row1!=row; row1++)
            {
                if(arr[row][col]==arr[row1][col])
                c++;
                if(c==2)
                {
                    v++;
                    if(arr[row][col]==-1)
                    printf("\nYou Win!\n");
                    else if(arr[row][col]==-2)
                    printf("\nYou Lost.\n");
                    else
                    printf("\nIts a Draw\n");
                }
            }
    }


    //Diagonal check
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2])
    {
        printf("\nYou Win\n");
        return 1;
    }
    if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
    {
        printf("\nYou Win\n");
        return 1;
    }

    return 0;
}

/*int blockwin(int arr[3][3])
{
    int c=0;
    //horizontal check
    for(int row=0; row<3; row++)
        for(int col=0; col<3; col++)
            for(int col1=0; col1<3 && col1!=col; col1++)
            {
                if(arr[row][col]==arr[row][col1])
                c++;
                if(c==2)
                {
                    if(arr[row][col]==-1)
                    printf("You Win!");
                    else if(arr[row][col]==-2)
                    printf("You Lost.");
                    else
                    printf("Draw");
                    return 1;
                }
            }
}*/


int mini_wincheck(int arr[3][3])
{
    int num,c,h=0,v=0,difficulty=0;


    //horizontal check
    if(arr[0][0]==arr[0][1] && arr[0][1]==arr[0][2])
    if(arr[0][0]==-1)
    return -1;
    else return 1;

    if(arr[1][0]==arr[1][1] && arr[1][1]==arr[1][2])
    if(arr[1][0]==-1)
    return -1;
    else return 1;

    if(arr[2][0]==arr[2][1] && arr[2][1]==arr[2][2])
    if(arr[2][0]==-1)
    return -1;
    else return 1;


    //Vertical check
    if(arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0])
    if(arr[0][0]==-1)
    return -1;
    else return 1;

    if(arr[0][1]==arr[1][1] && arr[1][1]==arr[2][1])
    if(arr[0][1]==-1)
    return -1;
    else return 1;

    if(arr[0][2]==arr[1][2] && arr[1][2]==arr[2][2])
    if(arr[0][2]==-1)
    return -1;
    else return 1;


    //Diagonal check
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2])
    if(arr[0][0]==-1)
    return -1;
    else return 1;

    if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
    if(arr[0][2]==-1)
    return -1;
    else return 1;

    return 0;

}

int boardfull(int arr[3][3])
{
    int n=0;
    for(int row=0; row<3; row++)
    for(int col=0; col<3; col++)
    if(arr[row][col]!=-1 &&arr[row][col]!=-2)
    n++;

    if(n>0)
    return 0;
    else
    return 1;
}

int mini(int arr[3][3], int ai_turn)
{
    int row=0, col=0;

    int val=mini_wincheck(arr);
    if(val!=0)
    return val;
    
    if(boardfull(arr))
    return 0;

    if(ai_turn)
    {
        int bestscore= -2; int score;
        for(row=0; row<3; row++)
        for(col=0; col<3; col++)
        {
            int temp=arr[row][col];
            if(arr[row][col]!=-1 && arr[row][col]!=-2)
            {
                arr[row][col]=-2;
                score=mini(arr,0);
                if(score>bestscore)
                bestscore=score;

                arr[row][col]=temp;
            }

        }
        
        return bestscore;
    }
    else
    {
        int bestscore= 2; int score;
        for(row=0; row<3; row++)
        for(col=0; col<3; col++)
        {
            if(arr[row][col]!=-1 && arr[row][col]!=-2)
            {
                int temp=arr[row][col];
                arr[row][col]=-1;
                score=mini(arr,1);
                if(score<bestscore)
                bestscore=score;

                arr[row][col]=temp;
            }
        }
        return bestscore;
    }
}

int mini_move(int arr[3][3])
{
    int bestscore=-2, move, r,c;
    for(int row=0; row<3; row++)
    for(int col=0; col<3; col++)
    {
        if(arr[row][col]!=-1 && arr[row][col]!=-2)
        {
            int temp= arr[row][col];
            arr[row][col]=-2;
            int score=mini(arr,0);
            if(score>bestscore)
            {
                bestscore = score;
                r=row;
                c=col;
            }
            arr[row][col]=temp;
        }
    }
    return arr[r][c]=-2;
}

int process(int c,int n, int arr[3][3])
{
    if(c==9 ||wincheck(arr))
    return 0;
    else
    {
        userinput(&n, arr);
        yourmove(arr,&n);
        compmove(arr);
        return process(c+1,n,arr);
    }
}

int main()
{
    srand(time(NULL));
    int n,c=1, difficulty, first_move;
    int arr[3][3];
    printf("Choose difficulty level\n1: easy\n2: impossible: ");
    scanf("%d",&difficulty);

    printf("Press 1: You First\nPress 2: Ai First\n");
    scanf("%d",&first_move);
    printmat(arr);
    if(difficulty==1)
    process(c,n,arr);
    else

    if(first_move==1)
    {
        while(c<=9)
        {
            printf("your turn:\n");
            userinput(&n, arr);
            yourmove(arr,&n);
            c++;
            if(mini_wincheck(arr)==-1)
            {
                printf("You Lose");
                break;
            }
            else if(mini_wincheck(arr)==1)
            {
                printf("You Win!");
                break;
            }
            if(boardfull(arr))
            {
                printf("Its a draw");
                break;
            }
            printf("ai turn:\n");
            mini_move(arr);
            printnewmat(arr);
            c++;
            if(mini_wincheck(arr)==-1)
            {
                printf("You Win!");
                break;
            }
            else if(mini_wincheck(arr)==1)
            {
                printf("You Lose.");
                break;
            }

            if(boardfull(arr))
            {
                printf("Its a draw");
                break;
            }
        }
        return 0;
    }
    else
        {
        while(c<=9)
        {
            printf("ai turn:\n");
            mini_move(arr);
            printnewmat(arr);
            c++;
            if(mini_wincheck(arr)==-1)
            {
                printf("You Win!");
                break;
            }
            else if(mini_wincheck(arr)==1)
            {
                printf("You Lose.");
                break;
            }

            if(boardfull(arr))
            {
                printf("Its a draw");
                break;
            }
            printf("your turn:\n");
            userinput(&n, arr);
            yourmove(arr,&n);
            c++;
            if(mini_wincheck(arr)==-1)
            {
                printf("You Win!");
                break;
            }
            else if(mini_wincheck(arr)==1)
            {
                printf("You Lose");
                break;
            }
            if(boardfull(arr))
            {
                printf("Its a draw");
                break;
            }
        }
        return 0;
    }
}