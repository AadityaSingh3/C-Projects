#include<stdio.h>
#include<math.h>
#include<time.h>
/*
int countTriples(int n)
{
    int count=0;
    for(int c=1; c<=n; c++)
        for(int a=1; a<n; a++)
            for(int b=1; b<=n; b++)
            {
                if((c*c)==a*a+b*b)
                {
                    count++;
                    printf("(%d,%d,%d) ",a,b,c);
                }
            }
    return count;
}

int countTriples(int n) {
    int count = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            int c2 = a*a + b*b;
            int c = sqrt(c2);
            if (c <= n && c*c == c2)
                count++;
        }
    }
    return count;
}
    */

int countTriples(int n)
{
    int i=0;
    while(i<=n)
    {
        
    }
    return
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();   // Start timer
    int n=10;
    int tri=countTriples(n);
    printf("\n\n\n\n%d",tri);

    end = clock();     // End timer

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken: %f seconds\n", cpu_time_used);
}