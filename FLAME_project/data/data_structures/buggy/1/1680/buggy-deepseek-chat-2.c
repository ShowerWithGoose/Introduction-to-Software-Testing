#include<stdio.h>
int N,i,j,b[20];
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
        a[2*m]='\0';
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ The loop variable i is global, causing incorrect behavior in recursion. It should be declared as local (e.g., int i) to avoid interference between recursive calls.
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