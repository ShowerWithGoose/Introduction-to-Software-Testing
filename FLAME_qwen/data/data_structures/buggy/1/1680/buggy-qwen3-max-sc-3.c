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
        for(i=1;i<2*N;i+=2) // @@ [The loop iterates over odd indices up to 2*N-1, but it should iterate over numbers 1 to N directly. This causes incorrect indexing and logic for generating permutations. Also, using global variable 'i' in recursive function leads to interference between recursive calls.]
        {
        if(b[(i+1)/2] == 0) // @@ [Because 'i' is global and modified in recursive calls, (i+1)/2 does not reliably represent the intended number from 1 to N. This breaks the permutation logic.]
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ [Writing to a[m] and a[m+1] assumes two characters per number, but recursion advances m by 2, which mismatches with the actual length needed when N > 9 (though N<=10, '10' needs two digits). However, since N<=10, number 10 would be represented as ':' (ASCII 58) due to '0'+10, which is invalid. But more critically, the indexing of 'a' is inconsistent with how m is updated.]
            a[m+1] = ' ';
            re(m+2,n-1); // @@ [Recursing with m+2 assumes each number takes two characters (digit + space), but this fails for numbers >=10 (like 10), and also leaves trailing space at end of string. Additionally, because m is advanced by 2 per element, the null terminator position a[2*m] becomes incorrect when base case is reached.]
            b[(i+1)/2] = 0;
        }
    }
}