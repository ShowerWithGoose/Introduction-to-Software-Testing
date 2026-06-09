#include<stdio.h>
int N,i,j,b[20];
char a[20]; // @@ Array size insufficient for N=10; should be at least 21 for the null terminator.
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
        a[2*m]='\0'; // @@ Wrong index; should be a[m] because m is the next free index after the last character.
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ Global variable i causes interference between recursive calls; should be declared as local int.
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