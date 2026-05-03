#include <stdio.h>
int main()
{
    int sud[9][9], invalrow=0,invalcol=0,invalchunk=0, valchunk=0, valrow=0, valcol=0, num;
printf("ENTER THE SUDOKU MATRIX. \nPRESS 0 TO ERASE");
    //input the matrix
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("\nelement for Row: %d Column:%d :  ",i+1,j+1);
            scanf("%d",&sud[i][j]);
            if(sud[i][j]==0)
            {
                if(i==0 && j==0)
                {
                    printf("No value entered to erase");
                    j-=1;
                }
                else if(j==0)
                {
                    i-=1;
                    j=7;
                }
                else
                j-=2;
            }
            else if(sud[i][j]>9 || sud[i][j]<0)
            {
                printf("NUMBER GREATER THAN 9, THUS INVALID\n");
                printf("Try again\n");
                printf("element for Row: %d Column:%d :  ",i+1,j+1);
            scanf("%d",&sud[i][j]);
            }
        }
    }

/*
    //checking rows
    for(int i=0; i<3; i++)
    {
            if(sud[i][0]!=sud[i][1])
            {
                if(sud[i][0]!=sud[i][2])
                {
                    if(sud[i][1]!=sud[i][2])
                    valrow++;
                    else
                    invalrow++;
                }
                else
                    invalrow++;
            }
            else
                    invalrow++;
    }
    
    printf("\n\n");
    //checking columns
        for(int j=0; j<3; j++)
    {
            if(sud[0][j]!=sud[1][j])
            {
                if(sud[0][j]!=sud[2][j])
                {
                    if(sud[1][j]!=sud[2][j])
                    valcol++;
                    else
                    invalcol++;
                }
                else
                    invalcol++;
            }
            else
                    invalcol++;
    }
    */
    
    
    //validity of row with loops
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            num=sud[i][j];
            for(int k=0; k<9; k++)
            {
                if(num==sud[i][k]&&k!=j)
                {
                    invalrow++;
                }
                else
                valrow++;
            }
        }
    }
    
    
    //validity of col with loops
    for(int j=0; j<9; j++)
        for(int i=0; i<9; i++)
        {
            num=sud[i][j];
            for(int k=0; k<9; k++)
            {
                if(num==sud[k][j] &&k!=i)
                invalcol++;
                else
                valcol++;
            }
        }
    
    
    
    //check each chunk
    /*for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)*/
                for(int k=0; k<9;k+=3)
                    for(int l=0; l<9;l+=3)
                    {
                        for(int m=k; m<k+3; m++)
                            for(int n=l; n<l+3; n++)
                                for(int o=0; o<k+3; o++)
                                    for(int p=0; p<l+3; p++)
                                    {
                                        if(sud[m][n]==sud[o][p] && n!=p)
                                        {
                                        printf("Row %d Column %d = Row %d Column %d \nThus INVALID \n",m+1,n+1,o+1,p+1);
                                        invalchunk++;
                                        }
                                        else
                                        valchunk++;
                                    }
                    }




    //printing the matrix
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d  ",sud[i][j]);
            if((j+1)%3==0)
            printf("|");
        }
        printf("\n");
    }
    if(invalcol>1 || invalrow>1 || invalchunk>1)
    printf("Sudoku is INVALID\n");
    else
    printf("Sudoku is VALID\n");
}