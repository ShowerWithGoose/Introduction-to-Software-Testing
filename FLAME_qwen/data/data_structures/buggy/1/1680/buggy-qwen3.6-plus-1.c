#include<stdio.h>
int N,i,j,b[20]; // @@ Variable 'i' is declared globally, which will be overwritten during recursive calls, breaking the loop logic. It should be local to 're'.
char a[20]; // @@ Array size is too small to hold permutations for N up to 10 (requires at least 30 characters).
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
        a[2*m]='\0'; // @@ 'm' already represents the current string index, so 'a[2*m]' goes out of bounds. It should be 'a[m]'.
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ Using global 'i' in a recursive function causes loop state corruption. 'i' should be declared locally inside 're'.
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