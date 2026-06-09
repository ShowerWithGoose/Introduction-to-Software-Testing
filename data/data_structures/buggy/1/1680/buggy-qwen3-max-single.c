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
        for(i=1;i<2*N;i+=2) // @@ [The loop iterates over odd indices up to 2*N-1, but it should iterate over numbers 1 to N. This causes incorrect indexing and logic for generating permutations. Also, using global variable 'i' in recursion leads to interference between recursive calls.]
        {
        if(b[(i+1)/2] == 0) // @@ [Because 'i' is global and modified in recursive calls, the value of (i+1)/2 becomes unpredictable during backtracking, leading to incorrect marking/unmarking and skipped or duplicated numbers.]
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ [Writing only one character per number assumes single-digit numbers (which is okay for N<=10), but the indexing 'm' and 'm+1' doesn't align with the loop's step of i+=2; also, space is added at m+1 but next call uses m+2, which may leave trailing space or overwrite.]
            a[m+1] = ' ';
            re(m+2,n-1); // @@ [Incrementing m by 2 assumes two characters per number (digit + space), but when n==0, the string is null-terminated at a[2*m], which may not match actual written length, possibly causing undefined behavior or extra spaces.]
            b[(i+1)/2] = 0;
        }
    }
}