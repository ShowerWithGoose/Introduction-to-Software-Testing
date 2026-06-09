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
            a[m] = (i+1)/2+'0'; @@ [The index 'm' is used to write into array 'a', but the recursive call increments m by 2, so writing at 'm' and 'm+1' assumes two characters per number. However, when N >= 10, numbers like 10 require two digits, but the code only writes one character ('0' + value), which fails for values > 9. Also, the loop condition i<2*N causes incorrect iteration range—it should iterate over numbers 1 to N, not odd indices up to 2*N-1.]
            a[m+1] = ' ';
            re(m+2,n-1); @@ [The recursion step increases m by 2 assuming each number takes two characters (digit + space), but this breaks for multi-digit numbers (e.g., 10). Additionally, the base case sets a[2*m] = '\0', which may overwrite or misalign the string due to inconsistent indexing.]
            b[(i+1)/2] = 0;
        }
    }
}