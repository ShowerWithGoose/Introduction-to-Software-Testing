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
        for(k=0;k<a;k++) // @@ Error: The loop condition should be k<b (or k<=b-1) to print all n elements. Since b is the length n, and a==b, the loop only prints up to a-1, missing the last element. For n=2, it prints only 1 element instead of 2.
        {
            printf("%d",s[k]);
        }
        printf("\n");
    }
    else
    {
        int l;
        for(l=a;l<b;l++) // @@ Error: The loop should iterate from l=a to l<b, but the algorithm incorrectly uses change2 and change1 without properly generating all permutations. The logic for generating permutations is flawed; it does not produce all permutations in lexicographic order and may miss some or produce duplicates. For n=2, it only outputs "12" and "21" without spaces, but the expected output requires spaces between numbers.
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