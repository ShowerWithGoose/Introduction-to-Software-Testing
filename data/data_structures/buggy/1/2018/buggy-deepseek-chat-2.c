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
        for(k=0;k<a;k++) // @@ Error: should be k < b (or k < n) to print all n elements; here a equals b, but b is the end index (n), so loop should go to b, not a
        {
            printf("%d",s[k]);
        }
        printf("\n");
    }
    else
    {
        int l;
        for(l=a;l<b;l++) // @@ Error: loop should be l = a; l < b; l++ to include all positions from a to b-1, but the recursive call uses a+1 and b unchanged, which is correct; however, the initial call pai(s,0,n) means b = n, so this loop runs l from 0 to n-1, which is correct for generating permutations. The actual bug is in the base case printing.
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