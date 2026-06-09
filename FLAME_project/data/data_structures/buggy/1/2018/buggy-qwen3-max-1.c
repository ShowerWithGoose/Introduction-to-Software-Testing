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
            printf("%d",s[k]); // @@ [The output format is incorrect: numbers should be separated by spaces, but this prints them concatenated without spaces. Also, it only prints 'a' elements instead of 'b' (which equals n), so for input 2 it prints only the first element when a==b==2, but loop runs k=0 to k<2, which is correct in count, but missing space separation.]
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
    pai(s,0,n);
    return 0;
}