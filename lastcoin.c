#include <stdio.h>
int mini(int n, int ai_turn)
{
    if(n==0)
    return ai_turn? -1: 1;

    if(ai_turn)
    {
        int best =-2;
        if(n>=1)          //try one
        {     
            int score = mini(n-1, 0);
            if(score>best)
            best=score;
        }

        if(n>=2)    //try two
        {
            int score = mini(n-2, 0);
            if(score>best)
            best=score;
        }
        return best;
    }
    else
    {                                  //human turn
        int best =2;
        if(n>=1)                       //try one
        {
            int score=mini(n-1, 1);
            if(score<best)
            best = score;
        }

        if(n>=2)                      //try two
        {
            int score=mini(n-2, 1);
            if(score<best)
            best=score;
        }

        return best;

    }
}

int move(int n)
{
    int bestscore= -2; int move;
    int score1=mini(n-1, 0);
    if(score1>bestscore)
    {
        bestscore= score1;
        move =1;
    }

    int score2=mini(n-2, 0);
    if(score2>bestscore)
    {
        bestscore=score2;
        move = 2;
    }

    return move;
}

int main()
{
    int n, ai_turn, Hinp, Ainp, turn;
    int val;
    printf("Enter total number of coins: ");
    scanf("%d",&n);
    printf("press 1 to move first, and 2 for ai to move first: ");
    scanf("%d",&turn);

    while(n>0)
    {
        if(turn==1)
        {
            printf("Remaining coins: %d\n", n);
            printf("your turn: ");
            scanf("%d",&Hinp);
            n-=Hinp;
            printf("Remaining %d\n",n);
            if(n<=0)
            { 
                printf("You Win!");
                break;
            }

            Ainp=move(n);
            printf("Ai chooses %d\n",Ainp);
            n-=Ainp;
            printf("Remaining coins: %d\n", n);
            if(n<=0)
            {
                printf("You Lose.");
                break;
            }
        }

        else if(turn==2)
        {
            printf("Remaining coins: %d\n", n);
            Ainp=move(n);
            printf("Ai chooses %d\n",Ainp);
            n-=Ainp;
            printf("Remaining coins: %d\n", n);
            if(n<=0)
            { 
                printf("You Lose.");
                break;
            }
            printf("your turn: ");
            scanf("%d",&Hinp);
            n-=Hinp;
            printf("Remaining %d\n",n);
            if(n<=0)
            { 
                printf("You Win!");
                break;
            }

        }
    }
    
}