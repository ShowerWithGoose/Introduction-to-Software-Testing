#include <stdio.h>
int v[15];//to judge wehther v[*] has been used
int a[15];//to book the final result
int n;//the number
void perm(int k);//to generate full permutation
int main ()
{
    scanf("%d", &n);
    perm(1);
    return 0;
}
void perm(int k)
{
    if(k>n)//sign of ending
    {
        int x=1;
        for(x=1;x<=n;x++)
        {
            printf("%d", a[x]); // @@ Missing space after number; should be printf("%d ", a[x]); to match output format (integers separated by spaces).
        }
        printf("\n");
    }
    
    int y=1;
    for(y=1;y<=n;y++)//depth-first algorithm
    {
        if(v[y]!=1)
        {
            v[y]=1;
            a[k]=y;
            perm(k+1);
            v[y]=0;//re-sign v[*] for anther road
            a[k]=0;
        }
    }
}