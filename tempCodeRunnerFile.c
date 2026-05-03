int process(int c,int n, int arr[3][3])
{
    if(c==9 ||wincheck(arr))
    {
        wincheck(arr);
        return 0;
    }
    else
    {
        userinput(&n);
        yourmove(arr,&n);
        compmove(arr);
        return process(c+1,n,arr);
    }
}