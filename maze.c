#include<stdio.h>
#include<stdbool.h>

int arr[3][3]={{1,1,1},
               {1,0,1},
               {0,1,1}
              };

int path[3][3];

bool isValid(int x, int y)
{
    if(x<0 || y<0 || x>2 || y>2 || arr[x][y]==0 || path[x][y]==1)
        return false;
    return true;
}

bool solvemaze(int x, int y)
{
    // Check if destination reached
    if(x==2 && y==2 && arr[x][y]==1)
    {
        path[x][y]=1;
        return true;   // ✅ FIXED
    }

    if(isValid(x,y))
    {
        path[x][y]=1;

        if(solvemaze(x+1,y)) return true;
        if(solvemaze(x,y+1)) return true;
        if(solvemaze(x-1,y)) return true;
        if(solvemaze(x,y-1)) return true;

        // Backtracking
        path[x][y]=0;
        return false;
    }
    return false;
}

void printpath(int arr[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    if(solvemaze(0,0))
        printpath(path);
    else
        printf("No path found");
}
