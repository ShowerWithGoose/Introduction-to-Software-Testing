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
        for(i=1;i<2*N;i+=2) // @@ [The loop iterates over odd indices up to 2*N-1, which maps to numbers 1..N via (i+1)/2, but this unnecessarily complicates indexing and causes incorrect placement in the output array `a`. The index `m` is incremented by 2 in recursion but used as a byte offset without accounting for proper string formatting. Also, when N=10, (i+1)/2+'0' produces non-printable or incorrect ASCII because '0'+10 is not the character "10" — it fails for N>=10 since digits >9 can't be represented as single chars.]
        {
        if(b[(i+1)/2] == 0)
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ [This only works for numbers 1–9. For N=10, (i+1)/2 can be 10, and '0'+10 is ':', not "10". Thus, multi-digit numbers are not handled, violating the problem's requirement for N up to 10.]
            a[m+1] = ' ';
            re(m+2,n-1); // @@ [Recursing with m+2 assumes each number takes 2 characters (digit + space), which breaks when numbers have more than one digit (e.g., 10). This leads to buffer overflow or malformed output for N>=10.]
            b[(i+1)/2] = 0;
        }
    }
}