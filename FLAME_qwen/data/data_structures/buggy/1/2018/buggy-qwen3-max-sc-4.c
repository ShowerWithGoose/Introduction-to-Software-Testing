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
    int s[10];
    int n;
    scanf("%d",&n);
    int g;
    for(g=0;g<n;g++)
    {
        s[g]=g+1;
    }
    pai(s,0,n); // @@ [Incorrect initial call: should generate permutations of size n, but loop in pai uses 'a==b' as base case and iterates up to b-1, causing missing last element and wrong permutation count]
    return 0;
}