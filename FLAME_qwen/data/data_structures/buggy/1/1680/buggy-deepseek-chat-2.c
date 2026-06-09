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
        a[2*m]='\0'; // @@ The index calculation is incorrect. In the reference program, the null terminator is placed at ret[2*a+1], but here it uses a[2*m], which does not match the indexing scheme used for storing characters.
        puts(a);
        return;
    }
        for(i=1;i<2*N;i+=2) // @@ The loop iterates over odd indices from 1 to 2*N-1, but this does not correctly map to numbers 1 to N. The reference program loops i from 1 to n (the number of elements), not over array indices. This causes incorrect permutation generation.
        {
        if(b[(i+1)/2] == 0) // @@ The mapping (i+1)/2 is used to convert index to number, but the loop variable i is not directly related to the number being placed. This logic is convoluted and error-prone compared to the reference's simple i from 1 to n.
        {
            b[(i+1)/2] = 1;
            a[m] = (i+1)/2+'0'; // @@ The character is placed at a[m] instead of a[2*m] as in the reference, causing misalignment in the output string.
            a[m+1] = ' '; // @@ The space is placed at a[m+1] instead of a[2*m+1], which does not match the reference's indexing scheme.
            re(m+2,n-1); // @@ The recursion passes m+2, but the reference passes a+1 (incrementing the position counter by 1, not 2). This mismatch leads to incorrect string construction.
            b[(i+1)/2] = 0;
        }
    }
}