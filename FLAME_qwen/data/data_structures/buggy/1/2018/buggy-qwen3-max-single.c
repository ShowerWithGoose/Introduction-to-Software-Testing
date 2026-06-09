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
        for(k=0;k<a;k++)
        {
            printf("%d",s[k]); // @@ [Missing space between numbers as required by output format; should print "%d " instead of "%d"]
        }
        printf("\n");
    }
    else
    {
        int l;
        for(l=a;l<b;l++)
        {
            change2(s,a,l);
            pai(s,a+1,b);
            change1(s,a,l);
        }
    }
}
int main()
{
    int s[10]; // @@ [Array size is 10, but N can be up to 10, requiring indices 0..9 (size 10) — this is actually sufficient, so not an error]
    int n;
    scanf("%d",&n);
    int g;
    for(g=0;g<n;g++)
    {
        s[g]=g+1;
    }
    pai(s,0,n); // @@ [The recursive function expects the last index to be n-1, but passes n; this causes off-by-one error in base case and loop bounds]
    return 0;
}