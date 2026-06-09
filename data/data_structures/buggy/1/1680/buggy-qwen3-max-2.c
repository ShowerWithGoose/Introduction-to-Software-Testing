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
        if(b[(i+1)/2] == 0) // @@ [Because 'i' is global and modified in recursive calls, (i+1)/2 does not reliably represent the intended number from 1 to N. This breaks the permutation logic.]
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ [Storing digit character at position 'm', but next character is stored at 'm+1'. However, recursive call uses 'm+2', which assumes two characters per number. But for multi-digit numbers (though not possible here since N<=10), this would fail. More critically, the indexing into 'a' is inconsistent with how the string is built and null-terminated.]
            a[m+1] = ' ';
            re(m+2,n-1); // @@ [Passing m+2 assumes each number takes two characters (digit + space), but when n==0, the null terminator is placed at a[2*m], which may overwrite or misalign due to inconsistent indexing. Also, the final space is not removed, leading to trailing space in output which may affect correctness depending on checker strictness.]
            b[(i+1)/2] = 0;
        }
    }
}