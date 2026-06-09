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
        for(i=1;i<2*N;i+=2) // @@ [The loop condition `i<2*N` causes the loop to run only up to i=2*N-1, which corresponds to number N, but the indexing and logic for generating permutations is flawed. More critically, the use of global variables `i` and `b` in recursive calls leads to incorrect state management because `i` is modified across recursive levels, breaking the loop control in parent calls. Additionally, the output format includes a trailing space on each line due to always appending ' ' after every number, but the expected output requires space-separated numbers without trailing space. However, the primary error causing wrong answer (only one line printed) is that the global variable `i` is shared across recursive calls, so when deeper recursions modify `i`, the loop in upper levels gets corrupted.]
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