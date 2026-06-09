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
            a[m] = (i+1)/2+'0'; @@ [The index 'm' is used to store the digit, but in recursive calls 'm' is incremented by 2, so the next digit will be written at 'm+2', leaving a gap. However, the current assignment writes only one character per level, but the loop increments i by 2 and uses (i+1)/2 which complicates mapping. More critically, the array 'a' is indexed by 'm', but 'm' increases by 2 on each recursion, so positions a[m+1], a[m+3], etc., are never initialized before being printed, leading to garbage output. Also, the base case sets a[2*m] = '\0', but during recursion, characters are written at a[m], a[m+1], which mismatches the indexing logic.]
            a[m+1] = ' '; @@ [This writes a space at m+1, but in the next recursive call, m becomes m+2, so the next digit is placed at a[m+2]. However, the base case null-terminates at a[2*m], which does not align with how characters were stored. This indexing inconsistency causes incorrect string formation and potential buffer overruns or unterminated strings.]
            re(m+2,n-1); @@ [The recursion advances m by 2, but the storage logic in a[m] and a[m+1] assumes that each number takes two characters (digit + space), yet the base case uses 2*m as the null-terminator index, which doesn't match the actual write positions. This leads to malformed output strings.]
            b[(i+1)/2] = 0;
        }
    }
}