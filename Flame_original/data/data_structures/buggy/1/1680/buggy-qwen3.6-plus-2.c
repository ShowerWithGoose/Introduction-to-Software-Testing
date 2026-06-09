#include<stdio.h>
int N,i,j,b[20]; // @@ The variable 'i' is declared globally, which will be overwritten during recursive calls, breaking the loop logic. It should be declared locally inside the function.
char a[20];
void re(int m,int n);
int main()
{
scanf("%d",&N);
re(0,N);
return 0;
}
void re(int m,int n)
{
    if(n==0)
    {
        a[2*m]='\0'; // @@ Incorrect index for the null terminator. When n==0, m equals 2*N, so 2*m points far beyond the current string. It should be a[m-1]='\0'; to properly terminate the string.
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ Using the global variable 'i' in a recursive function's loop causes state corruption across recursive calls. 'i' must be declared locally (e.g., int i;).
        {
        if(b[(i+1)/2] == 0)
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0';
            a[m+1] = ' ';
            re(m+2,n-1);
            b[(i+1)/2] = 0;
        }
    }
}