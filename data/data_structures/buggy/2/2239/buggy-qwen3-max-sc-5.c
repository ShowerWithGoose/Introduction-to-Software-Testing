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
    } // @@ [The loop condition `scanf("%d",&a[i])!=EOF` does not stop at '='. It tries to read an integer after the last number, which fails when '=' is encountered, leading to undefined behavior or infinite loop. The input ends with '=', but this code doesn't check for it.]

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
                a[r]=a[r]*a[j+1]; // @@ [Accesses a[j+1] without ensuring j+1 < i. When the last operator is '*', j+1 may be out of bounds. Also, the logic assumes operators apply to next number, but indexing is off because b[i] stores operator after a[i], yet expression ends with '=', so b[i-1] is '=', and a[i] is never read correctly.]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same as above: potential out-of-bounds access to a[j+1]. Also, integer division is required, but this may work if operands are integers, though safety is compromised.]
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
                a[r]=a[r]+a[j+1]; // @@ [Again, accesses a[j+1] without bounds check. Additionally, modifying loop variable `j` inside the loop causes skipped iterations and incorrect parsing.]
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