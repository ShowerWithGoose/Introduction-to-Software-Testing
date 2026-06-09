#include<stdio.h>
int N,i,j,b[20]; // @@ [Error: global variable i is used as loop variable in recursive function, causing interference between recursion levels. Should be local.]
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
        a[2*m]='\0'; // @@ [Error: incorrectly computes index for null terminator. Should be a[m]='\0'; for current m. This also risks out-of-bounds for larger N.]
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ [Error: using global variable i; in recursion, the loop variable is shared, leading to incorrect iteration. Declare a local int i.]
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