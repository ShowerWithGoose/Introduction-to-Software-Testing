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
    } // @@ [The loop condition `scanf(...) != EOF` does not stop at '='. It will keep reading past the '=' or fail to detect end of input properly, leading to undefined behavior or infinite loop. The problem requires stopping when '=' is encountered, but this code never checks for it.]

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
                a[r]=a[r]*a[j+1]; // @@ [Accesses a[j+1] without ensuring j+1 < i. If the last operator is '*', this reads beyond array bounds. Also, logic assumes operators apply to next number, but indexing is off because b[i-1] is likely '=', and a[i] was never read for it.]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same as above: potential out-of-bounds access to a[j+1]. Also, integer division is required, which is okay in C with ints, but only if operands are valid.]
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
                a[r]=a[r]+a[j+1]; // @@ [Again, accesses a[j+1] without bound check. Additionally, modifying loop variable `j` inside the loop causes skipped iterations and unpredictable behavior.]
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
                a[r]=a[r]-a[j+1]; // @@ [Same issues: modifies loop index `j`, leading to incorrect traversal; potential out-of-bounds access.]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}