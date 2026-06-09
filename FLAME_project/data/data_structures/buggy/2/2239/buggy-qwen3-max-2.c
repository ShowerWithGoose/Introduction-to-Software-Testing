#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[20];
char b[20];
int c[20];

int main()
{
    int i=0;
    char d;
    while (scanf("%d",&a[i])!=EOF)
    {
        scanf("%c",&d);
        while (d==' ')
        {
            scanf("%c",&d);
        }
        b[i]=d;
        c[i]=1;
        i+=1;
    } // @@ [The loop condition `scanf("%d", ...) != EOF` fails when encountering '=' because it's not an integer, causing premature termination and missing the last number or operator. Also, the '=' is never checked to stop input parsing.]

    int s=0;
    for (int j=0;j<i;j++)
    {
        printf("%c %d\n",b[j],a[j]);
    }
    
    for (int j=0;j<i;j++)
    {
        if ((b[j]=='*')||(b[j]=='/'))
        {
            s+=1;
        }
        
    }
    int y=i-1-s;
    if (s!=0)
    {
        for (int j=0;j<i;j++)
        {
            if (b[j]=='*')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]*a[j+1]; // @@ [This accesses a[j+1] without ensuring j+1 < i; also, after marking c[j+1]=0, later operations may skip needed values or access invalid indices.]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same issue: potential out-of-bounds access to a[j+1]; also, integer division is correct per problem, but logic flow is flawed due to incorrect parsing.]
                c[j+1]=0;
            }
        }
    }
    if (y!=0)
    {
        for (int j=0;j<i;j++)
        {
            if (b[j]=='+')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                while (c[j+1]!=1)
                {
                    j++;
                }
                a[r]=a[r]+a[j+1]; // @@ [Modifying loop variable `j` inside the loop causes skipped iterations and incorrect operand pairing.]
                c[j+1]=0;
            }
            else if (b[j]=='-')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                while (c[j+1]!=1)
                {
                    j++;
                }
                a[r]=a[r]-a[j+1]; // @@ [Same issue: modifying `j` inside loop leads to incorrect traversal and operand selection.]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]); // @@ [Assumes result is always in a[0], but due to flawed parsing and processing, a[0] may not hold the final result.]
    return 0;
    
}