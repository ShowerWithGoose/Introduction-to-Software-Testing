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
        for(i=1;i<2*N;i+=2) // @@ [The loop condition `i < 2*N` causes the loop to run only for odd indices up to 2*N-1, which maps to numbers 1 through N correctly, but the use of global variable `i` leads to incorrect loop behavior during recursion because recursive calls modify the same `i`. This breaks the loop invariant in parent calls.]
        {
        if(b[(i+1)/2] == 0)
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ [This converts numbers >9 incorrectly since it assumes single-digit output. However, since N<=10, number 10 would be represented as ':' (ASCII 58), not "10". But more critically, the output format requires space-separated integers, not characters; this approach fails for N>=10 and also doesn't produce lexicographical order due to flawed recursion control.]
            a[m+1] = ' ';
            re(m+2,n-1);
            b[(i+1)/2] = 0;
        }
    }
}