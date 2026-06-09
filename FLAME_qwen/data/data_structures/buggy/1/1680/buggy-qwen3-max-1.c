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
            a[m] = (i+1)/2+'0'; @@ [Incorrect indexing: 'm' should correspond to character position for the current depth, but using 'm' directly leads to overwriting and incorrect spacing; also, space is written at a[m+1], but next call uses m+2, causing misalignment]
            a[m+1] = ' '; @@ [Writes space even after the last number, leading to trailing space which may cause presentation error or mismatch in expected output format]
            re(m+2,n-1); @@ [Passing m+2 assumes two characters per number (digit + space), but this causes buffer overflow when m approaches array size and doesn't handle multi-digit numbers (though N<=10 so digits are single, but trailing space remains an issue)]
            b[(i+1)/2] = 0;
        }
    }
}