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
    } // @@ [The loop condition `scanf("%d",&a[i])!=EOF` does not stop at '='. It will keep trying to read integers even after '=', leading to undefined behavior or infinite loop when non-integer input (like '=') is encountered.]

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
                a[r]=a[r]*a[j+1]; // @@ [Accesses a[j+1] which may be out of valid data range; also, logic assumes operands are adjacent but doesn't account for consumed terms properly.]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same issue: accesses a[j+1] without ensuring it's valid; also integer division is correct per spec, but indexing/logic is flawed.]
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
                    j++; // @@ [Modifying loop variable `j` inside the loop causes skipped iterations and unpredictable behavior.]
                }
                a[r]=a[r]+a[j+1]; // @@ [Again accesses a[j+1] which may be invalid; also, after incrementing j in loop, j+1 could be beyond array bounds.]
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
                    j++; // @@ [Same problem: modifying loop counter `j` inside loop leads to incorrect iteration and potential out-of-bounds access.]
                }
                a[r]=a[r]-a[j+1]; // @@ [Potential out-of-bounds access and incorrect operand selection due to flawed traversal logic.]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}