#include <stdio.h>
void change1(int s[],int a,int b)
{
    int i;
    int z=s[a];
    for(i=a;i<b;i++)
    {
        s[i]=s[i+1];
    }
    s[b]=z;
}
void change2(int s[],int a,int b)
{
    int i;
    int z=s[b];
    for(i=b;i>a;i--)
    {
        s[i]=s[i-1];
    }
    s[a]=z;
}
void pai(int s[],int a,int b)
{
    if(a==b)
    {
        int k;
        for(k=0;k<a;k++) // @@ Error: The loop condition should be k<b (or k<=b-1) to print all n elements. Since b is the length n, the loop should run from 0 to b-1. Currently it runs from 0 to a-1, which is one less than needed when a==b.
        {
            printf("%d",s[k]);
        }
        printf("\n");
    }
    else
    {
        int l;
        for(l=a;l<b;l++) // @@ Error: The loop should include l=b to generate all permutations. The range should be l=a to l<b (which is correct for 0-indexed), but the logic of change2 and change1 with this loop does not produce all permutations correctly. The main issue is that the loop should iterate l from a to b-1, but the algorithm is flawed because it doesn't handle the case where l=b (the last element) properly, leading to missing permutations.
        {
            change2(s,a,l);
            pai(s,a+1,b);
            change1(s,a,l);
        }
    }
}
int main()
{
    int s[10];
    int n;
    scanf("%d",&n);
    int g;
    for(g=0;g<n;g++)
    {
        s[g]=g+1;
    }
    pai(s,0,n);
    return 0;
}