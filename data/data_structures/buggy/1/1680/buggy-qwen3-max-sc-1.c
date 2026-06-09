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
        for(i=1;i<2*N;i+=2)
        {
        if(b[(i+1)/2] == 0)
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0';
            a[m+1] = ' ';
            re(m+2,n-1); @@ [The recursive call uses m+2, but the next position to write should be m+2 only if each number takes two characters (digit + space). However, when n==1 (last number), an extra space is added at the end, and more critically, the indexing logic is inconsistent: m tracks byte index in 'a', but the loop iterates over odd indices i to simulate numbers 1..N. This causes incorrect placement of digits and spaces, leading to buffer overflow or malformed output. Also, the base case sets a[2*m] = '\0', implying that total length is 2*m, but during recursion, two bytes (digit and space) are written per level, so for N=2, m goes 0 -> 2 -> 4, and a[4] = '\0', which is correct length, but the loop condition i<2*N is wrong because it should iterate over numbers 1..N, not over 1,3,...,2N-1. The expression (i+1)/2 gives 1..N, but using i in this way is unnecessarily complex and error-prone. The real bug is that the output includes a trailing space at the end of each line, which may not match expected format, but more severely, for N=10, (i+1)/2 becomes 10, and '0'+10 is not a valid digit character—it produces ':'. Thus, the program fails for N>=10 because it tries to store multi-digit numbers as single characters.]
            b[(i+1)/2] = 0;
        }
    }
}