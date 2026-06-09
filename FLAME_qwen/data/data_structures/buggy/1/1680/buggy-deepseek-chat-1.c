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
        a[2*m]='\0'; // @@ The index calculation is incorrect; should be a[2*m] but the array is filled at positions m and m+1, so the null terminator should be at position m (since m increments by 2 each recursion, the last valid character is at m-1). This causes buffer overflow and incorrect output.
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ The loop iterates over odd indices from 1 to 2N-1, but the logic for mapping to numbers is flawed. It should iterate over numbers 1 to N directly, not over array indices. This causes incorrect permutation generation and potential out-of-bounds access.
        {
        if(b[(i+1)/2] == 0) // @@ The index (i+1)/2 maps odd i to numbers, but the loop variable i is not directly related to the number being placed. This works only by coincidence for small N but is logically incorrect and confusing.
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ The character is placed at position m, but the array a is indexed by m (which increments by 2), so positions are not contiguous. This leads to incorrect string formatting.
            a[m+1] = ' '; // @@ The space is placed at m+1, but the next recursion uses m+2, leaving gaps in the array. This causes the output to have extra spaces or missing characters.
            re(m+2,n-1);
            b[(i+1)/2] = 0;
        }
    }
}