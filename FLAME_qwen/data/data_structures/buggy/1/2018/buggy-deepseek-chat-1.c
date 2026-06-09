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
        for(k=0;k<a;k++) // @@ The loop condition should be k < b (or k < n) to print all n elements, but here a equals b, and b is the original n, so this prints only a elements (which is n), but the loop starts from 0 and goes to a-1, which is correct for printing n elements. However, the issue is that the loop prints without spaces between numbers, and the base case should be a == b-1 or similar to match the recursive logic.
        {
            printf("%d",s[k]); // @@ Missing space between numbers; should be "%d " to match expected output format.
        }
        printf("\n");
    }
    else
    {
        int l;
        for(l=a;l<b;l++) // @@ The loop should go from l=a to l<b, but the recursive call uses a+1 and b unchanged, which means the last element is never swapped into position a. The correct range should be l=a to l<b, but the logic of change2 and change1 is swapped compared to the reference program. In the reference, re (which is like change2) is called first, then der (like change1) is called after recursion. Here change2 is called first, then change1, which is correct, but the loop range should be l=a to l<b, and the base case should be a == b-1 to handle the last element properly.
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